section .text

global ft_strlen

;	size_t	ft_strlen(const char *s)

ft_strlen:
	cmp		rdi, 0
	je		_null
	push	rdi
	push	rsi
	push	rcx
	mov		rcx, 0xffffffffffffffff
	mov		al, 0
	cld
	repne	scasb
	sub		rdi, 1
	mov		rax, rdi
	pop		rcx
	pop		rsi
	pop		rdi
	sub		rax, rdi
	ret

_null:
	mov	rax, 0
	ret
