;
; 
; Inputs:   
; Outputs:  
global _ft_strcmp
_ft_strcmp:
	mov	rax, -1								;counter
_ft_strcmp_loop:
	inc rax
	cmp	byte [rdi + rax], 0					;str1 == \0
	je	return
	cmp	byte [rdi + rax], byte [rsi + rax]		;str1 == str2
	je	_ft_strcmp_loop
	jmp return
return:
	sub	byte [rdi + rax], byte [rsi + rax]
	mov eax, rdi
	ret