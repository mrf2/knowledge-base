; Tell assembler: this is a flat binary, no headers
BITS 32
ORG 0x100000	; just arbitrary load address for bootloader-style flat binary

mov eax, 1	; syscall: write
mov ebx, 1	; stdout
mov ecx, msg
mov edx, msglen
int 0x80

; Linux 32-bit syscall: exit(0)
MOV EAX, 1	; syscall nuber for sys_exit
xor EBX, EBX	; status = 0
int 0x80	; trigger syscall

msg: db "Hello", 10
msglen equ $ - msg

