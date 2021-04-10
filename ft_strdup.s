extern _ft_strlen
extern _ft_strcpy
extern _malloc

global _ft_strdup
section .text
_ft_strdup:

; char *strdup(const char *str);
; void *malloc(size_t sizemem)
; rdi str
    mov     rcx, rdi    ; save str in rcx
    push    rcx         ; save rcx
    call    _ft_strlen  ; len str in rax
    mov     rdi, rax
    inc     rdi         ; \0
    call    _malloc     ; new str in rax
    cmp     rax, 0      ; is malloc fail?
    je      return
    mov     rdi, rax
    pop     rcx
    mov     rsi, rcx
    call    _ft_strcpy
    ret
return:
    xor     rax, rax
    ret
