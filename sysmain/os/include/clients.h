#ifndef CLIENTS_H
#define CLIENTS_H

// use this header to make better headers!

// Macros
// Use it for conditional compilation (#ifdef) or a random text replacement you want ;)
#define MAX_BUFFER_SIZE 256
#define DEVICE_NAME     "VoiddevReturn0"
#define ENABLE_LOGGING  1  // 1 to enable, 0 to disable

// Constants
// Use it for fixed numerical or string values
// Here, use `inline constexpr int` for integers and Booleans for enable/disable flags

inline constexpr int    DEFAULT_TIMEOUT_MS = 2000;

inline constexpr bool  API_IS_ENABLED           = true; // 1 for enable, 0 to disable. 0 is strongly discouraged for this.

inline constexpr bool DEVICE_NAME           = true; // 1 activates device name, 0 disables it

inline constexpr bool CLIENTS_DEBUG_FLAGS           = CDF_LUMEN_TRUE

#endif // CLIENTS_H