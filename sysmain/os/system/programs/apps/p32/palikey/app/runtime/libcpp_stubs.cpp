// libcpp_stubs.cpp
// Purpose: satisfy libc++ symbols in a freestanding, nostdlib environment
// WARNING: these are hard stubs. Any call will intentionally halt.

#include <stddef.h>

extern "C" {

// Global fallback (some toolchains still reference this)
void __libcpp_verbose_abort(const char*, ...) {
    for (;;) { }
}

} // extern "C"

/* ---------------------------------------------------------
 * libc++ NDK namespace stubs
 * --------------------------------------------------------- */
namespace std {
namespace __ndk1 {

// libc++ abort path used by __throw_* helpers
void __libcpp_verbose_abort(const char*, ...) {
    for (;;) { }
}

/* ---------------------------------------------------------
 * basic_string minimal ABI stubs
 * --------------------------------------------------------- */

template <class T>
class allocator {
public:
    allocator() noexcept {}
};

template <class CharT>
struct char_traits {
};

template <class CharT,
          class Traits = char_traits<CharT>,
          class Allocator = allocator<CharT>>
class basic_string {
public:
    basic_string() noexcept {}
    basic_string(const basic_string&) noexcept {}

    basic_string& operator=(const basic_string&) noexcept {
        // Do nothing — hard stub
        return *this;
    }
};

// Explicit instantiation for char string ABI
template class basic_string<char, char_traits<char>, allocator<char>>;

} // namespace __ndk1
} // namespace std

/* ---------------------------------------------------------
 * libc++ throw helpers (exceptions disabled, but symbols exist)
 * --------------------------------------------------------- */

extern "C" {

void __throw_length_error(const char*) {
    for (;;) { }
}

void __throw_out_of_range(const char*) {
    for (;;) { }
}

void __throw_bad_array_new_length() {
    for (;;) { }
}

}