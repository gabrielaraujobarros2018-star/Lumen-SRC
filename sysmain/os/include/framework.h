#ifndef FRAMEWORK_H
#define FRAMEWORK_H

// use this header to make better headers!

// Macros
// Use it for conditional compilation (#ifdef) or a random text replacement you want ;)
#define MAX_BUFFER_SIZE 10000
#define DEVICE_NAME     "VoiddevReturn0"
#define ENABLE_LOGGING  0  // 1 to enable, 0 to disable
#define ENABLE_ADMIN_PERMISSION  1 // if set to 0, Frameworks wont have admin access to system

// Constants
// Use it for fixed numerical or string values
// Here, use `inline constexpr int` for integers and Booleans for enable/disable flags

inline constexpr int    DEFAULT_TIMEOUT_MS = 2000;

inline constexpr int    DEFAULT_COOLDOWN_MS = 2000 // cooldown to protect device from crashes during lag. This intentionally makes the device lag.

inline constexpr bool  FRAMEWORK_IS_ADMIN           = true; // true for enable, false to disable.

inline constexpr bool DEVICE_NAME           = true; // true activates device name, false disables it

#endif // FRAMEWORK_H