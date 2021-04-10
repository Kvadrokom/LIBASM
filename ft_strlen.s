global _ft_strlen
section .text
_ft_strlen:
	push rdi			
	xor rax, rax
again:
	cmp byte [rdi], 0		; if str end?
	je return				; then quit
	inc rax					; else rax++ (counter)
	inc rdi					; next *str
	jmp again
return:
	pop rdi
	ret