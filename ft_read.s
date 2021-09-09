; Attempts to read nbyte bytes of data from the object referenced by the descriptor fildes into the buffer pointed to by buf.
; 
; Inputs:	RSI = file desciptor to read from (fd)
;			RDI = reading buffer (buff)
;			RDX = size of bytes read (nbyte)
; Outputs:	EAX = Upon successful completion the number of bytes which were written is returned.
;			Otherwise, a -1 is returned and the global variable errno is set to indicate the error.
global _ft_read
extern ___error
_ft_read:
	mov rax, 0x2000003
	syscall
	jc _syscall_error
	ret
_syscall_error:
	push rax
	call ___error
	pop qword [rax]
	mov rax, -1
	ret