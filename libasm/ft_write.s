; Attempts to write nbyte of data to the object referenced by the descriptor fildes from the buffer pointed to by buf.
; 
; Inputs:   RSI = file desciptor to write in (fd)
;			RDI = buffer to write (buff)
;			RDX = size of bytes to write (nbyte)
; Outputs:  EAX = Upon successful completion the number of bytes which were written is returned.
;				Otherwise, a -1 is returned and the global variable errno is set to indicate the error.
global _ft_write
extern ___error
_ft_write:
	mov rax, 0x2000004
	syscall
	jc _syscall_error
	ret
_syscall_error:
	push rax			; saves errno
	call ___error		; retrieves address to errno
	pop qword [rax]		; put errno in return value of __error (pointer to errno)
	mov rax, -1
	ret