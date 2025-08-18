; hello64.asm - poisition-independent flag binary (no headers)
BITS 64
ORG 0

	; write(1, msg, msglen)
	mov rax, 1		;sys_write
	mov rdi, 1		; fd = stdout
	lea rsi, [rel msg]	; pointer to data (RIP - relative)
	mov rdx, msglen
	syscall

	; exit (0)
	mov rax, 60		; sys_exit
	xor rdi, rdi
	syscall
msg:	db "Hello, world!", 10
msglen:	equ $-msg

