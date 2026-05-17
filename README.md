# User Manager – C++ Web Service for Online User Tracking

A lightweight, header‑only HTTP server written in **C++17** (using `cpp-httplib`).  
No heavy dependencies – just the standard library and a single header file.

### Features
- `GET /loguser?name=xxx` – register user login  
- `GET /logout?name=xxx` – register user logout  
- `GET /userslist` – list all currently online users  
- `GET /deluser?name=xxx` – forcibly remove a user  
- Thread‑safe (std::mutex)  
- In‑memory storage (can easily be extended to file/DB)

Perfect for lightweight monitoring, tiny side projects, or as a learning example.

---

## Quick Start

### Requirements
- C++17 compiler (g++ 7+, clang 5+, or MSVC 2017+)
- Linux / macOS / Windows (WSL recommended for Windows)

### Build & Run

```bash
# Clone (or just download the two files)
git clone https://github.com/ha1ron23/Web-User-Manager.git
cd Web-User-Manager

# Compile
```bash
g++ -std=c++17 -pthread web_user_manager.cpp -o user_manager
```

# Run
```bash
./web_user_manager
```
**The Server starts at http://localhost:8080**

# API Examples

```bash
# User Alice logs in
curl "http://localhost:8080/loguser?name=alice"

# Show online users
curl "http://localhost:8080/userslist"

# User Bob logs in
curl "http://localhost:8080/loguser?name=bob"

# Alice logs out
curl "http://localhost:8080/logout?name=alice"

# Force delete Bob (even if still "online")
curl "http://localhost:8080/deluser?name=bob"
```

**Responses are plain text,that means it's easy to parse or extend to JSON**

# License

**MIT License**