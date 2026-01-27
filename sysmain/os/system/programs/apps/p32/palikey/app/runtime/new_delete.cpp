#include <stddef.h>

extern "C" void* palisade_alloc(size_t);
extern "C" void  palisade_free(void*);

void* operator new(size_t size) {
    return palisade_alloc(size);
}

void* operator new[](size_t size) {
    return palisade_alloc(size);
}

void operator delete(void* ptr) noexcept {
    palisade_free(ptr);
}

void operator delete[](void* ptr) noexcept {
    palisade_free(ptr);
}

/* sized delete — REQUIRED */
void operator delete(void* ptr, size_t) noexcept {
    palisade_free(ptr);
}

void operator delete[](void* ptr, size_t) noexcept {
    palisade_free(ptr);
}

extern "C" void __cxa_pure_virtual() {
    for (;;) { }
}