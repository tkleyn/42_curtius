; copies the string src to dst (including the terminating `\0' character).
; 
; Inputs:   RDI = destination string (dst)
;			RDI = source string (src)
; Outputs:  
global _ft_strcpy
_ft_strcpy:
	push r12
	mov r12, rdi
loop:
	mov cl, byte[rsi]
	mov [rdi], cl
	cmp cl, 0				;src == \0
	jz end
	inc rdi
	inc rsi
	jmp loop
end:
	mov rax, r12
	pop r12
	ret