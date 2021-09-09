;Compares 2 0 terminated strings.
;
; Inputs:	RDI = s1
;			RSI = s2
; Outputs:	EAX = an integer greater than,
;				equal to, or less than 0, according as the string s1 is greater than,
;				equal to, or less than the string s2.
global _ft_strcmp
_ft_strcmp:
	mov	rax, -1								;index
_ft_strcmp_loop:
	inc rax
	mov dl, byte [rdi + rax]
	cmp	dl, 0								;str1 == \0
	je	return
	cmp	dl, byte [rsi + rax]				;str1 == str2
	je	_ft_strcmp_loop
	jmp return
return:
	movzx ebx, byte [rsi + rax] 
	movzx eax, dl
	sub	eax, ebx
	ret