; wrap_elf.asm - tiny ELF64 that jumps into the embedded flat blob
BITS 64
default rel
global _start

section .text
_start:
	lea rbx, [rel payload]	; rbx = address of embedded blob
	jmp rbx			; tail-jump into it
section .rodata
payload:
	incbin "hello64.bin"	; embed that raw flat binary here
