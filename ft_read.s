extern ___error

global _ft_read
section .text

; rdi unsigned int fd, rsi char *buf, rdx size_t count

_ft_read:
    mov			rax, 0x2000003
    syscall
	jc			error			; if error CF == 1, rax = code error
   	ret
error:
	push		rax				; save code error
	call		___error		; set *ptr on erno in rax
	pop			r8				; get code error
	mov			[rax], r8		; set code in erno
	mov 		rax, -1			; return -1
	ret