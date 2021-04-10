global _ft_strcmp
section .text
_ft_strcmp:

; int strcmp(const char *string1, const char *string2);
; rdi 1 arg, rsi 2 arg

	mov 	rdx, rsi
	mov 	rcx, rdi
again:
	xor		rax, rax			; rax = 0
	add		al, [rcx]			; copy 1 byte to al from string1
	cmp		al, [rdx]			; compare al with 1 byte from string2
	jl 		less				; if less jump to "less"
	sub 	al, [rdx]			; if not, save in al "*string1 - *string2" 
	cmp 	al, 0				; compare al
	jne 	return
	cmp		byte [rdx], 0
	je 		return
	cmp		byte [rcx], 0
	je 		return
	inc		rdx
	inc		rcx
	jmp 	again
return:
	ret
less:
	mov 	al, [rdx]
	sub 	al, [rcx]
	neg 	rax
	ret