;
; 
; Inputs:   
; Outputs:  
extern _ft_strcpy
extern _malloc
extern _ft_strlen
global _ft_strdup
extern ___error
_ft_strdup:
	push rdi
	call _ft_strlen
	inc rax
	mov rdi, rax
	call _malloc
	cmp rax, byte 0
	je _malloc_error
	pop rsi
	mov rdi, rax
	call _ft_strcpy
	ret
_malloc_error:
	push rax
	call ___error
	pop qword [rax]
	mov rax, 0
	ret