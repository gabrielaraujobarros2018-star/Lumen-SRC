global display_control_enable
section .text

display_control_enable:
    mov eax, 0xB8000
    mov byte [eax], ' '
    mov byte [eax+1], 0x07
    ret