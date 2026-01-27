#pragma once

#define PALISADE_BUILD_ID   "b01162026-SP1"

#if defined(__x86_64__)
#define PALISADE_ARCH "x86_64"
#elif defined(__aarch64__)
#define PALISADE_ARCH "arm64"
#else
#define PALISADE_ARCH "unknown"
#endif