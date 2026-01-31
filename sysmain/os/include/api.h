#ifndef API_H
#define API_H

// use this header to make better headers!

// Macros
// Use it for conditional compilation (#ifdef) or a random text replacement you want ;)
#define MAX_BUFFER_SIZE 512
#define DEVICE_NAME     "VoiddevReturn0"
#define ENABLE_LOGGING  0  // 1 to enable, 0 to disable

// Constants
// Use it for fixed numerical or string values
// Here, use `inline constexpr int` for integers and Booleans for enable/disable flags

inline constexpr int    DEFAULT_TIMEOUT_MS = 5000;

inline constexpr bool  SHOW_API_DEBUG_FLAGS           = true; // true for enable, false to disable.

inline constexpr bool DEVICE_NAME_FLAG           = VDRZERO;

#endif // API_H
