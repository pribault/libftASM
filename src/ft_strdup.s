section .text

extern malloc
extern ft_strlen
extern ft_memcpy

global ft_strdup

;	char	*ft_strdup(const char *s);

ft_strdup:

_start:

	;	check the string

	cmp		rdi, 0
	je		_end_null

	;	get the string len

	mov		rbx, rdi
	
	call	ft_strlen

	push	rbx
	mov		rdi, rax
	push	rdi
	call	malloc

	;	check malloc return

	cmp		rax, 0
	je		_end_null

	;	ft_memcpy

	pop		rdx
	add		rdx, 1
	pop		rsi
	mov		rdi, rax
	call	ft_memcpy

_end:

	ret

_end_null:

	mov		rax, 0

	ret
