#include <stdint.h>
void sleep(){
    __asm__("cli");
    outb(0x64,0xFE);
}