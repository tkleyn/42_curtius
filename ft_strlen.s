; Determines the length of a 0 terminated string.
; 
; Inputs:   RDI = address of beginning of string
; Outputs:  RAX = length of the string, including the NUL terminator
global _ft_strlen
_ft_strlen:
	mov rax, -1
cnt_loop:
	inc rax
	cmp byte [rax + rdi], 0
	jne cnt_loop
	ret