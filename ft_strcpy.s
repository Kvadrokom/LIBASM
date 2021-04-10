global _ft_strcpy
section .text
_ft_strcpy:

    ; rdi 1 arg, rsi 2 arg
    ; char *strcpy(char *destptr, const char *srcptr)
	mov r8, rsi
	mov r9, rdi
	xor rax, rax
again:
	cmp byte [r8], 0		; if str end?
	je  return				; then quit
	mov cl, [r8]			; copy *destpyr =
	mov [r9], cl			; 		*srcptr
	inc r8					; destptr++
	inc r9					; srcptr++
	jmp again
return:
	mov cl, [r8]			; copy \0
	mov [r9], cl			; copy \0
	mov rax, rdi			; copy \0
	ret