;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; filename:dos_routine_file_read.asm 
; 16-bit real mode assembly (running under DOS)
; Open a file and read bytes (DOS file API)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
mov ah, 3DH		; DOS: Open file
mov al, 00h		; read-only
mov dx, offset filename
int 21h			; handle returned in AX

mov bx, ax		; file handle
mov ah, 3Fh		; DOS: read from file
mov cx, 512		; bytes to read
mov dx, offset buffer
int 21h
jc file_error

filename	db "TEST.DAT", 0
buffer		db 512 dup(?)
;...............................................................................
; DOS doesn't expose raw sectors normally. We ask for files. 
; DOS internally may call BIOS INT 13h to fetchc data from disk. 
;...............................................................................

