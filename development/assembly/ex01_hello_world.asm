; filename: ex01_hello_world.asm
; compile instruction: nasm -f elf32 ex01_hello_world.asm -o ex01_hello_world.o
; linker instruction: ld -m elf_i386  ex01_hello_world.o -o ex01_hello_world
; run: ex01_hello_world

section .data
	msg db "Hello, world!", 0Ah	; message with newline
	len equ $ - msg			; length of message

section .text
	global _start

_start:
	; write(1, msg, len)
	mov eax, 4	; syscall number for write
	mov ebx, 1	; file descriptor (stdout)
	mov ecx, msg	; pointer to string
	mov edx, len	; string length
	int 0x80	; interrupt to call kernel

	; exit(0)
	mov eax, 1
	xor ebx, ebx
	int 0x80
