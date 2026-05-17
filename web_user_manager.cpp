#include <iostream>
#include <string>
#include <unordered_map>
#include <chrono>
#include <ctime>
#include <mutex>

#include "httplib.h"

using namespace httplib;

struct UserInfo {
    std::string name;
    std::string login_time;
};

std::unordered_map<std::string, UserInfo> online_users;
std::mutex users_mutex;

std::string current_time_str() {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    return std::ctime(&t);
}

int main() {
    Server svr;

    svr.Get("/loguser", [](const Request& req, Response& res) {
        if (!req.has_param("name")) {
            res.status = 400;
            res.set_content("Missing 'name' parameter", "text/plain");
            return;
        }
        std::string name = req.get_param_value("name");

        std::lock_guard<std::mutex> lock(users_mutex);
        if (online_users.find(name) != online_users.end()) {
            res.status = 409;
            res.set_content("User already logged in", "text/plain");
            return;
        }
        online_users[name] = {name, current_time_str()};
        res.set_content("OK: " + name + " logged in", "text/plain");
    });

    svr.Get("/logout", [](const Request& req, Response& res) {
        if (!req.has_param("name")) {
            res.status = 400;
            res.set_content("Missing 'name' parameter", "text/plain");
            return;
        }
        std::string name = req.get_param_value("name");

        std::lock_guard<std::mutex> lock(users_mutex);
        if (online_users.erase(name) == 0) {
            res.status = 404;
            res.set_content("User not found", "text/plain");
            return;
        }
        res.set_content("OK: " + name + " logged out", "text/plain");
    });

    svr.Get("/userslist", [](const Request&, Response& res) {
        std::lock_guard<std::mutex> lock(users_mutex);
        if (online_users.empty()) {
            res.set_content("No users online", "text/plain");
            return;
        }
        std::string result = "Online users:\n";
        for (const auto& pair : online_users) {
            result += "- " + pair.first + " (since " + pair.second.login_time + ")";
        }
        res.set_content(result, "text/plain");
    });

    svr.Get("/deluser", [](const Request& req, Response& res) {
        if (!req.has_param("name")) {
            res.status = 400;
            res.set_content("Missing 'name' parameter", "text/plain");
            return;
        }
        std::string name = req.get_param_value("name");

        std::lock_guard<std::mutex> lock(users_mutex);
        if (online_users.erase(name) == 0) {
            res.status = 404;
            res.set_content("User not found", "text/plain");
            return;
        }
        res.set_content("User " + name + " deleted", "text/plain");
    });

    svr.Get("/", [](const Request&, Response& res) {
        res.set_content(R"(
            <h1>User Manager API</h1>
            <ul>
                <li>GET /loguser?name=xxx - login user</li>
                <li>GET /logout?name=xxx - logout user</li>
                <li>GET /userslist - show online users</li>
                <li>GET /deluser?name=xxx - delete user</li>
            </ul>
        )", "text/html");
    });

    std::cout << "Starting web user manager on http://0.0.0.0:8080\n";
    svr.listen("0.0.0.0", 8080);

    return 0;
}