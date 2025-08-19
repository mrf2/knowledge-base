; filename: write_syscall.asm
; assemble:
; nasm -felf64 write_syscall.asm -o write_syscall.o 
; linking:
; ld write_syscall.o -o write_syscall

section .data
msg db "Hello, world!", 0x0A
msglen equ $ - msg

section .text
	global _start

_start:
	; syscall: write(1, msg, msglen)
	mov rax, 1		; syscall number (1 = write)
	mov rdi, 1		; fd = 1 (stdout)
	mov rsi, msg		; buf = &msg
	mov rdx, msglen		; count = msglen
	syscall

	; syscall: exit(0)
	mov rax, 60		; syscall number (60 = exit)
	xor rdi, rdi		; status = 0;
	syscall 
