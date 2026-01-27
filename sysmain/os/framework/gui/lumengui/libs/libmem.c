void gui_memset(void* p, int v, int n) {
    unsigned char* c = p;
    for (int i = 0; i < n; i++) c[i] = (unsigned char)v;
}