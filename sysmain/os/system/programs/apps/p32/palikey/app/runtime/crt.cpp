extern "C" int main();

extern "C" void _start() {
    main();
    for (;;) { }
}