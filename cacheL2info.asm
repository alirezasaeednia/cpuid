%include "io.inc"
section .text

global CMAIN

section .data
    format db "Cache L2 Line size: %d B, Assoc. type: %d, Cache size: %d KB.", 10, 0



CMAIN:
    push ebp
    mov ebp, esp
    push ebx
    push ecx
    push edx
    mov eax, 0x80000006
    cpuid
    PRINT_HEX 4,ecx

 
    leave
    ret