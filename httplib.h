//
//  httplib.h
//
//  Copyright (c) 2026 Yuji Hirose. All rights reserved.
//  MIT License
//

#ifndef CPPHTTPLIB_HTTPLIB_H
#define CPPHTTPLIB_HTTPLIB_H

#define CPPHTTPLIB_VERSION "0.45.0"
#define CPPHTTPLIB_VERSION_NUM "0x002d00"

#ifdef _WIN32
#if defined(_WIN32_WINNT) && _WIN32_WINNT < 0x0A00
#error                                                                         \
    "cpp-httplib doesn't support Windows 8 or lower. Please use Windows 10 or later."
#endif
#endif

/*
 * Configuration
 */

#ifndef CPPHTTPLIB_KEEPALIVE_TIMEOUT_SECOND
#define CPPHTTPLIB_KEEPALIVE_TIMEOUT_SECOND 5
#endif

#ifndef CPPHTTPLIB_KEEPALIVE_TIMEOUT_CHECK_INTERVAL_USECOND
#define CPPHTTPLIB_KEEPALIVE_TIMEOUT_CHECK_INTERVAL_USECOND 10000
#endif

#ifndef CPPHTTPLIB_KEEPALIVE_MAX_COUNT
#define CPPHTTPLIB_KEEPALIVE_MAX_COUNT 100
#endif

#ifndef CPPHTTPLIB_CONNECTION_TIMEOUT_SECOND
#define CPPHTTPLIB_CONNECTION_TIMEOUT_SECOND 300
#endif

#ifndef CPPHTTPLIB_CONNECTION_TIMEOUT_USECOND
#define CPPHTTPLIB_CONNECTION_TIMEOUT_USECOND 0
#endif

#ifndef CPPHTTPLIB_SERVER_READ_TIMEOUT_SECOND
#define CPPHTTPLIB_SERVER_READ_TIMEOUT_SECOND 5
#endif

#ifndef CPPHTTPLIB_SERVER_READ_TIMEOUT_USECOND
#define CPPHTTPLIB_SERVER_READ_TIMEOUT_USECOND 0
#endif

#ifndef CPPHTTPLIB_SERVER_WRITE_TIMEOUT_SECOND
#define CPPHTTPLIB_SERVER_WRITE_TIMEOUT_SECOND 5
#endif

#ifndef CPPHTTPLIB_SERVER_WRITE_TIMEOUT_USECOND
#define CPPHTTPLIB_SERVER_WRITE_TIMEOUT_USECOND 0
#endif

#ifndef CPPHTTPLIB_CLIENT_READ_TIMEOUT_SECOND
#define CPPHTTPLIB_CLIENT_READ_TIMEOUT_SECOND 300
#endif

#ifndef CPPHTTPLIB_CLIENT_READ_TIMEOUT_USECOND
#define CPPHTTPLIB_CLIENT_READ_TIMEOUT_USECOND 0
#endif

#ifndef CPPHTTPLIB_CLIENT_WRITE_TIMEOUT_SECOND
#define CPPHTTPLIB_CLIENT_WRITE_TIMEOUT_SECOND 5
#endif

#ifndef CPPHTTPLIB_CLIENT_WRITE_TIMEOUT_USECOND
#define CPPHTTPLIB_CLIENT_WRITE_TIMEOUT_USECOND 0
#endif

#ifndef CPPHTTPLIB_CLIENT_MAX_TIMEOUT_MSECOND
#define CPPHTTPLIB_CLIENT_MAX_TIMEOUT_MSECOND 0
#endif

#ifndef CPPHTTPLIB_EXPECT_100_THRESHOLD
#define CPPHTTPLIB_EXPECT_100_THRESHOLD 1024
#endif

#ifndef CPPHTTPLIB_EXPECT_100_TIMEOUT_MSECOND
#define CPPHTTPLIB_EXPECT_100_TIMEOUT_MSECOND 1000
#endif

#ifndef CPPHTTPLIB_WAIT_EARLY_SERVER_RESPONSE_THRESHOLD
#define CPPHTTPLIB_WAIT_EARLY_SERVER_RESPONSE_THRESHOLD (1024 * 1024)
#endif

#ifndef CPPHTTPLIB_WAIT_EARLY_SERVER_RESPONSE_TIMEOUT_MSECOND
#define CPPHTTPLIB_WAIT_EARLY_SERVER_RESPONSE_TIMEOUT_MSECOND 50
#endif

#ifndef CPPHTTPLIB_IDLE_INTERVAL_SECOND
#define CPPHTTPLIB_IDLE_INTERVAL_SECOND 0
#endif

#ifndef CPPHTTPLIB_IDLE_INTERVAL_USECOND
#ifdef _WIN32
#define CPPHTTPLIB_IDLE_INTERVAL_USECOND 1000
#else
#define CPPHTTPLIB_IDLE_INTERVAL_USECOND 0
#endif
#endif

#ifndef CPPHTTPLIB_REQUEST_URI_MAX_LENGTH
#define CPPHTTPLIB_REQUEST_URI_MAX_LENGTH 8192
#endif

#ifndef CPPHTTPLIB_HEADER_MAX_LENGTH
#define CPPHTTPLIB_HEADER_MAX_LENGTH 8192
#endif

#ifndef CPPHTTPLIB_HEADER_MAX_COUNT
#define CPPHTTPLIB_HEADER_MAX_COUNT 100
#endif

#ifndef CPPHTTPLIB_REDIRECT_MAX_COUNT
#define CPPHTTPLIB_REDIRECT_MAX_COUNT 20
#endif

#ifndef CPPHTTPLIB_MULTIPART_FORM_DATA_FILE_MAX_COUNT
#define CPPHTTPLIB_MULTIPART_FORM_DATA_FILE_MAX_COUNT 1024
#endif

#ifndef CPPHTTPLIB_PAYLOAD_MAX_LENGTH
#define CPPHTTPLIB_PAYLOAD_MAX_LENGTH (100 * 1024 * 1024) // 100MB
#endif

#ifndef CPPHTTPLIB_FORM_URL_ENCODED_PAYLOAD_MAX_LENGTH
#define CPPHTTPLIB_FORM_URL_ENCODED_PAYLOAD_MAX_LENGTH 8192
#endif

#ifndef CPPHTTPLIB_RANGE_MAX_COUNT
#define CPPHTTPLIB_RANGE_MAX_COUNT 1024
#endif

#ifndef CPPHTTPLIB_TCP_NODELAY
#define CPPHTTPLIB_TCP_NODELAY false
#endif

#ifndef CPPHTTPLIB_IPV6_V6ONLY
#define CPPHTTPLIB_IPV6_V6ONLY false
#endif

#ifndef CPPHTTPLIB_RECV_BUFSIZ
#define CPPHTTPLIB_RECV_BUFSIZ size_t(16384u)
#endif

#ifndef CPPHTTPLIB_SEND_BUFSIZ
#define CPPHTTPLIB_SEND_BUFSIZ size_t(16384u)
#endif

#ifndef CPPHTTPLIB_COMPRESSION_BUFSIZ
#define CPPHTTPLIB_COMPRESSION_BUFSIZ size_t(16384u)
#endif

#ifndef CPPHTTPLIB_THREAD_POOL_COUNT
#define CPPHTTPLIB_THREAD_POOL_COUNT                                           \
  ((std::max)(8u, std::thread::hardware_concurrency() > 0                      \
                      ? std::thread::hardware_concurrency() - 1                \
                      : 0))
#endif

#ifndef CPPHTTPLIB_THREAD_POOL_MAX_COUNT
#define CPPHTTPLIB_THREAD_POOL_MAX_COUNT (CPPHTTPLIB_THREAD_POOL_COUNT * 4)
#endif

#ifndef CPPHTTPLIB_THREAD_POOL_IDLE_TIMEOUT
#define CPPHTTPLIB_THREAD_POOL_IDLE_TIMEOUT 3 // seconds
#endif

#ifndef CPPHTTPLIB_RECV_FLAGS
#define CPPHTTPLIB_RECV_FLAGS 0
#endif

#ifndef CPPHTTPLIB_SEND_FLAGS
#define CPPHTTPLIB_SEND_FLAGS 0
#endif

#ifndef CPPHTTPLIB_LISTEN_BACKLOG
#define CPPHTTPLIB_LISTEN_BACKLOG 5
#endif

#ifndef CPPHTTPLIB_MAX_LINE_LENGTH
#define CPPHTTPLIB_MAX_LINE_LENGTH 32768
#endif

#ifndef CPPHTTPLIB_WEBSOCKET_MAX_PAYLOAD_LENGTH
#define CPPHTTPLIB_WEBSOCKET_MAX_PAYLOAD_LENGTH 16777216
#endif

#ifndef CPPHTTPLIB_WEBSOCKET_READ_TIMEOUT_SECOND
#define CPPHTTPLIB_WEBSOCKET_READ_TIMEOUT_SECOND 300
#endif

#ifndef CPPHTTPLIB_WEBSOCKET_CLOSE_TIMEOUT_SECOND
#define CPPHTTPLIB_WEBSOCKET_CLOSE_TIMEOUT_SECOND 5
#endif

#ifndef CPPHTTPLIB_WEBSOCKET_PING_INTERVAL_SECOND
#define CPPHTTPLIB_WEBSOCKET_PING_INTERVAL_SECOND 30
#endif

#ifndef CPPHTTPLIB_WEBSOCKET_MAX_MISSED_PONGS
#define CPPHTTPLIB_WEBSOCKET_MAX_MISSED_PONGS 0
#endif

/*
 * Headers
 */

#ifdef _WIN32
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif //_CRT_SECURE_NO_WARNINGS

#ifndef _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#endif //_CRT_NONSTDC_NO_DEPRECATE

#if defined(_MSC_VER)
#if _MSC_VER < 1900
#error Sorry, Visual Studio versions prior to 2015 are not supported
#endif

#pragma comment(lib, "ws2_32.lib")

#ifndef _SSIZE_T_DEFINED
using ssize_t = __int64;
#define _SSIZE_T_DEFINED
#endif
#endif // _MSC_VER

#ifndef S_ISREG
#define S_ISREG(m) (((m) & S_IFREG) == S_IFREG)
#endif // S_ISREG

#ifndef S_ISDIR
#define S_ISDIR(m) (((m) & S_IFDIR) == S_IFDIR)
#endif // S_ISDIR

#ifndef NOMINMAX
#define NOMINMAX
#endif // NOMINMAX

#include <io.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#if defined(__has_include)
#if __has_include(<afunix.h>)
// afunix.h uses types declared in winsock2.h, so has to be included after it.
#include <afunix.h>
#define CPPHTTPLIB_HAVE_AFUNIX_H 1
#endif
#endif

#ifndef WSA_FLAG_NO_HANDLE_INHERIT
#define WSA_FLAG_NO_HANDLE_INHERIT 0x80
#endif

using nfds_t = unsigned long;
using socket_t = SOCKET;
using socklen_t = int;

#else // not _WIN32

#include <arpa/inet.h>
#if !defined(_AIX) && !defined(__MVS__)
#include <ifaddrs.h>
#endif
#ifdef __MVS__
#include <strings.h>
#ifndef NI_MAXHOST
#define NI_MAXHOST 1025
#endif
#endif
#include <net/if.h>
#include <netdb.h>
#include <netinet/in.h>
#ifdef __linux__
#include <resolv.h>
#undef _res // Undefine _res macro to avoid conflicts with user code (#2278)
#endif
#include <csignal>
#include <netinet/tcp.h>
#include <poll.h>
#include <pthread.h>
#include <sys/mman.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

using socket_t = int;
#ifndef INVALID_SOCKET
#define INVALID_SOCKET (-1)
#endif
#endif //_WIN32

#if defined(__APPLE__)
#include <TargetConditionals.h>
#endif

#include <algorithm>
#include <array>
#include <atomic>
#include <cassert>
#include <cctype>
#include <chrono>
#include <climits>
#include <condition_variable>
#include <cstdlib>
#include <cstring>
#include <errno.h>
#include <exception>
#include <fcntl.h>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <sys/stat.h>
#include <system_error>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <utility>

// On macOS with a TLS backend, enable Keychain root certificates by default
// unless the user explicitly opts out.
#if defined(__APPLE__) && defined(__clang__) &&                                \
    !defined(CPPHTTPLIB_DISABLE_MACOSX_AUTOMATIC_ROOT_CERTIFICATES) &&         \
    (defined(CPPHTTPLIB_OPENSSL_SUPPORT) ||                                    \
     defined(CPPHTTPLIB_MBEDTLS_SUPPORT) ||                                    \
     defined(CPPHTTPLIB_WOLFSSL_SUPPORT))
#ifndef CPPHTTPLIB_USE_CERTS_FROM_MACOSX_KEYCHAIN
#define CPPHTTPLIB_USE_CERTS_FROM_MACOSX_KEYCHAIN
#endif
#endif

// On Windows, enable Schannel certificate verification by default
// unless the user explicitly opts out.
#if defined(_WIN32) &&                                                         \
    !defined(CPPHTTPLIB_DISABLE_WINDOWS_AUTOMATIC_ROOT_CERTIFICATES_UPDATE)
#define CPPHTTPLIB_WINDOWS_AUTOMATIC_ROOT_CERTIFICATES_UPDATE
#endif

#if defined(CPPHTTPLIB_USE_NON_BLOCKING_GETADDRINFO) ||                        \
    defined(CPPHTTPLIB_USE_CERTS_FROM_MACOSX_KEYCHAIN)
#if TARGET_OS_MAC && defined(__clang__)
#include <CFNetwork/CFHost.h>
#include <CoreFoundation/CoreFoundation.h>
#endif
#endif

#ifdef CPPHTTPLIB_OPENSSL_SUPPORT
#ifdef _WIN32
#include <wincrypt.h>

// these are defined in wincrypt.h and it breaks compilation if BoringSSL is
// used
#undef X509_NAME
#undef X509_CERT_PAIR
#undef X509_EXTENSIONS
#undef PKCS7_SIGNER_INFO

#ifdef _MSC_VER
#pragma comment(lib, "crypt32.lib")
#endif
#endif // _WIN32

#ifdef CPPHTTPLIB_USE_CERTS_FROM_MACOSX_KEYCHAIN
#if TARGET_OS_MAC
#include <Security/Security.h>
#endif
#endif

#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/ssl.h>
#include <openssl/x509v3.h>

#if defined(_WIN32) && defined(OPENSSL_USE_APPLINK)
#include <openssl/applink.c>
#endif

#include <iostream>
#include <sstream>

#if defined(OPENSSL_IS_BORINGSSL) || defined(LIBRESSL_VERSION_NUMBER)
#if OPENSSL_VERSION_NUMBER < 0x1010107f
#error Please use OpenSSL or a current version of BoringSSL
#endif
#define SSL_get1_peer_certificate SSL_get_peer_certificate
#elif OPENSSL_VERSION_NUMBER < 0x30000000L
#error Sorry, OpenSSL versions prior to 3.0.0 are not supported
#endif

#endif // CPPHTTPLIB_OPENSSL_SUPPORT

#ifdef CPPHTTPLIB_MBEDTLS_SUPPORT
#include <mbedtls/ctr_drbg.h>
#include <mbedtls/entropy.h>
#include <mbedtls/error.h>
#include <mbedtls/md5.h>
#include <mbedtls/net_sockets.h>
#include <mbedtls/oid.h>
#include <mbedtls/pk.h>
#include <mbedtls/sha1.h>
#include <mbedtls/sha256.h>
#include <mbedtls/sha512.h>
#include <mbedtls/ssl.h>
#include <mbedtls/x509_crt.h>
#ifdef _WIN32
#include <wincrypt.h>
#ifdef _MSC_VER
#pragma comment(lib, "crypt32.lib")
#endif
#endif // _WIN32
#ifdef CPPHTTPLIB_USE_CERTS_FROM_MACOSX_KEYCHAIN
#if TARGET_OS_MAC
#include <Security/Security.h>
#endif
#endif

// Mbed TLS 3.x API compatibility
#if MBEDTLS_VERSION_MAJOR >= 3
#define CPPHTTPLIB_MBEDTLS_V3
#endif

#endif // CPPHTTPLIB_MBEDTLS_SUPPORT

#ifdef CPPHTTPLIB_WOLFSSL_SUPPORT
#include <wolfssl/options.h>

#include <wolfssl/openssl/x509v3.h>

// Fallback definitions for older wolfSSL versions (e.g., 5.6.6)
#ifndef WOLFSSL_GEN_EMAIL
#define WOLFSSL_GEN_EMAIL 1
#endif
#ifndef WOLFSSL_GEN_DNS
#define WOLFSSL_GEN_DNS 2
#endif
#ifndef WOLFSSL_GEN_URI
#define WOLFSSL_GEN_URI 6
#endif
#ifndef WOLFSSL_GEN_IPADD
#define WOLFSSL_GEN_IPADD 7
#endif

#include <wolfssl/ssl.h>
#include <wolfssl/wolfcrypt/hash.h>
#include <wolfssl/wolfcrypt/md5.h>
#include <wolfssl/wolfcrypt/sha256.h>
#include <wolfssl/wolfcrypt/sha512.h>
#ifdef _WIN32
#include <wincrypt.h>
#ifdef _MSC_VER
#pragma comment(lib, "crypt32.lib")
#endif
#endif // _WIN32
#ifdef CPPHTTPLIB_USE_CERTS_FROM_MACOSX_KEYCHAIN
#if TARGET_OS_MAC
#include <Security/Security.h>
#endif
#endif
#endif // CPPHTTPLIB_WOLFSSL_SUPPORT

// Define CPPHTTPLIB_SSL_ENABLED if any SSL backend is available
#if defined(CPPHTTPLIB_OPENSSL_SUPPORT) ||                                     \
    defined(CPPHTTPLIB_MBEDTLS_SUPPORT) || defined(CPPHTTPLIB_WOLFSSL_SUPPORT)
#define CPPHTTPLIB_SSL_ENABLED
#endif

#ifdef CPPHTTPLIB_ZLIB_SUPPORT
#include <zlib.h>
#endif

#ifdef CPPHTTPLIB_BROTLI_SUPPORT
#include <brotli/decode.h>
#include <brotli/encode.h>
#endif

#ifdef CPPHTTPLIB_ZSTD_SUPPORT
#include <zstd.h>
#endif

/*
 * Declaration
 */
namespace httplib {

namespace ws {
class WebSocket;
} // namespace ws

namespace detail {

/*
 * Backport std::make_unique from C++14.
 *
 * NOTE: This code came up with the following stackoverflow post:
 * https://stackoverflow.com/questions/10149840/c-arrays-and-make-unique
 *
 */

template <class T, class... Args>
typename std::enable_if<!std::is_array<T>::value, std::unique_ptr<T>>::type
make_unique(Args &&...args) {
  return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

template <class T>
typename std::enable_if<std::is_array<T>::value, std::unique_ptr<T>>::type
make_unique(std::size_t n) {
  typedef typename std::remove_extent<T>::type RT;
  return std::unique_ptr<T>(new RT[n]);
}

namespace case_ignore {

inline unsigned char to_lower(int c) {
  const static unsigned char table[256] = {
      0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   10,  11,  12,  13,  14,
      15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,
      30,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,
      45,  46,  47,  48,  49,  50,  51,  52,  53,  54,  55,  56,  57,  58,  59,
      60,  61,  62,  63,  64,  97,  98,  99,  100, 101, 102, 103, 104, 105, 106,
      107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121,
      122, 91,  92,  93,  94,  95,  96,  97,  98,  99,  100, 101, 102, 103, 104,
      105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119,
      120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134,
      135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149,
      150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164,
      165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179,
      180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 224, 225, 226,
      227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241,
      242, 243, 244, 245, 246, 215, 248, 249, 250, 251, 252, 253, 254, 223, 224,
      225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239,
      240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254,
      255,
  };
  return table[(unsigned char)(char)c];
}

inline std::string to_lower(const std::string &s) {
  std::string result = s;
  std::transform(
      result.begin(), result.end(), result.begin(),
      [](unsigned char c) { return static_cast<char>(to_lower(c)); });
  return result;
}

inline bool equal(const std::string &a, const std::string &b) {
  return a.size() == b.size() &&
         std::equal(a.begin(), a.end(), b.begin(), [](char ca, char cb) {
           return to_lower(ca) == to_lower(cb);
         });
}

struct equal_to {
  bool operator()(const std::string &a, const std::string &b) const {
    return equal(a, b);
  }
};

struct hash {
  size_t operator()(const std::string &key) const {
    return hash_core(key.data(), key.size(), 0);
  }

  size_t hash_core(const char *s, size_t l, size_t h) const {
    return (l == 0) ? h
                    : hash_core(s + 1, l - 1,
                                // Unsets the 6 high bits of h, therefore no
                                // overflow happens
                                (((std::numeric_limits<size_t>::max)() >> 6) &
                                 h * 33) ^
                                    static_cast<unsigned char>(to_lower(*s)));
  }
};

template <typename T>
using unordered_set = std::unordered_set<T, detail::case_ignore::hash,
                                         detail::case_ignore::equal_to>;

} // namespace case_ignore

// This is based on
// "http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4189".

struct scope_exit {
  explicit scope_exit(std::function<void(void)> &&f)
      : exit_function(std::move(f)), execute_on_destruction{true} {}

  scope_exit(scope_exit &&rhs) noexcept
      : exit_function(std::move(rhs.exit_function)),
        execute_on_destruction{rhs.execute_on_destruction} {
    rhs.release();
  }

  ~scope_exit() {
    if (execute_on_destruction) { this->exit_function(); }
  }

  void release() { this->execute_on_destruction = false; }

private:
  scope_exit(const scope_exit &) = delete;
  void operator=(const scope_exit &) = delete;
  scope_exit &operator=(scope_exit &&) = delete;

  std::function<void(void)> exit_function;
  bool execute_on_destruction;
};

// Simple from_chars implementation for integer and double types (C++17
// substitute)
template <typename T> struct from_chars_result {
  const char *ptr;
  std::errc ec;
};

template <typename T>
inline from_chars_result<T> from_chars(const char *first, const char *last,
                                       T &value, int base = 10) {
  value = 0;
  const char *p = first;
  bool negative = false;

  if (p != last && *p == '-') {
    negative = true;
    ++p;
  }
  if (p == last) { return {first, std::errc::invalid_argument}; }

  T result = 0;
  for (; p != last; ++p) {
    char c = *p;
    int digit = -1;
    if ('0' <= c && c <= '9') {
      digit = c - '0';
    } else if ('a' <= c && c <= 'z') {
      digit = c - 'a' + 10;
    } else if ('A' <= c && c <= 'Z') {
      digit = c - 'A' + 10;
    } else {
      break;
    }

    if (digit < 0 || digit >= base) { break; }
    if (result > ((std::numeric_limits<T>::max)() - digit) / base) {
      return {p, std::errc::result_out_of_range};
    }
    result = result * base + digit;
  }

  if (p == first || (negative && p == first + 1)) {
    return {first, std::errc::invalid_argument};
  }

  value = negative ? -result : result;
  return {p, std::errc{}};
}

// from_chars for double (simple wrapper for strtod)
inline from_chars_result<double> from_chars(const char *first, const char *last,
                                            double &value) {
  std::string s(first, last);
  char *endptr = nullptr;
  errno = 0;
  value = std::strtod(s.c_str(), &endptr);
  if (endptr == s.c_str()) { return {first, std::errc::invalid_argument}; }
  if (errno == ERANGE) {
    return {first + (endptr - s.c_str()), std::errc::result_out_of_range};
  }
  return {first + (endptr - s.c_str()), std::errc{}};
}

inline bool parse_port(const char *s, size_t len, int &port) {
  int val = 0;
  auto r = from_chars(s, s + len, val);
  if (r.ec != std::errc{} || val < 1 || val > 65535) { return false; }
  port = val;
  return true;
}

inline bool parse_port(const std::string &s, int &port) {
  return parse_port(s.data(), s.size(), port);
}

struct UrlComponents {
  std::string scheme;
  std::string host;
  std::string port;
  std::string path;
  std::string query;
};

inline bool parse_url(const std::string &url, UrlComponents &uc) {
  uc = {};
  size_t pos = 0;

  auto sep = url.find("://");
  if (sep != std::string::npos) {
    uc.scheme = url.substr(0, sep);

    // Scheme must be [a-z]+ only
    if (uc.scheme.empty()) { return false; }
    for (auto c : uc.scheme) {
      if (c < 'a' || c > 'z') { return false; }
    }

    pos = sep + 3;
  } else if (url.compare(0, 2, "//") == 0) {
    pos = 2;
  }

  auto has_authority_prefix = pos > 0;
  auto has_authority = has_authority_prefix || (!url.empty() && url[0] != '/' &&
                                                url[0] != '?' && url[0] != '#');
  if (has_authority) {
    if (pos < url.size() && url[pos] == '[') {
      auto close = url.find(']', pos);
      if (close == std::string::npos) { return false; }
      uc.host = url.substr(pos + 1, close - pos - 1);

      // IPv6 host must be [a-fA-F0-9:]+ only
      if (uc.host.empty()) { return false; }
      for (auto c : uc.host) {
        if (!((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F') ||
              (c >= '0' && c <= '9') || c == ':')) {
          return false;
        }
      }

      pos = close + 1;
    } else {
      auto end = url.find_first_of(":/?#", pos);
      if (end == std::st