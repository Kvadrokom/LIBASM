extern ___error

global _ft_write
section .text
; fd = rdi, buffer = rsi, bytes = rdx
_ft_write:
    mov rax, 0x2000004
    syscall						; if error CF == 1, rax = code error
	jc			error
   	ret
error:
	push		rax				; save code error
	call		___error		; set *ptr on erno in rax
	pop			r8				; get code error
	mov			[rax], r8		; set code in erno
	mov 		rax, -1			; return -1
	ret