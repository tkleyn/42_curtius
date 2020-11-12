; Computes the length of the string s.
; 
; Inputs:   RDI = address of beginning of s
; Outputs:  RAX = the number of characters that precede the terminating NUL character.
global _ft_strlen
_ft_strlen:
	mov rax, -1
	cmp rdi, byte 0
	jne cnt_loop
	inc rax
	ret
cnt_loop:
	inc rax
	cmp byte [rax + rdi], byte 0
	jne cnt_loop
	ret