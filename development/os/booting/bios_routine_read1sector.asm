;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; filename: bios_routine_read1sector.asm
; Code snippet for reading 1 sector from disk
; CHS => Cylinder = 0; Head = 0; Sector = 1
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

mov ah, 02h		; BIOS: read sector function
mov al, 01h		; number of sectors to read
mov ch, 00h		; cylinder 0
mov cl, 01h		; sector 1
mov dh, 00h		; head 0
mov dl, 80h		; drive 0x80 = first hard disk
mov bx, 0x7C00		; buffer (ES:BX) = 0000:7C00
int 13H			; call BIOS disk service
jc disk_error		; check carry flag = error

;...............................................................................
; Direct Hardware Access: BIOS talks straight to disk controller
; Bootloaders like GRUB, NTLDR, etc. start out like this
;...............................................................................

