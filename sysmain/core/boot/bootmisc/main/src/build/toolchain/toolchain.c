int toolchain_is_clang(void) {
#ifdef __clang__
    return 1;
#else
    return 0;
#endif
}