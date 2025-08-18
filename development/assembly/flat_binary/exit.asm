; Tell assembler: this is a flat binary, no headers
BITS 32
ORG 0x0

; Linux 32-bit syscall: exit(0)
MOV EAX, 1	; syscall nuber for sys_exit
xor EBX, EBX	; status = 0
int 0x80	; trigger syscall

