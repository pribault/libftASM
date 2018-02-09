section .text

extern	_malloc
extern	_ft_strlen
extern	_ft_memcpy

global _ft_strdup

	;	char	*ft_strdup(const char *s);

_ft_strdup:

_start:

	push	rbp

	;	check the string

	cmp		rdi, 0
	je		_end_null

	;	get the string len

	push	rdi
	
	call	_ft_strlen

	mov		rdi, rax
	push	rdi
	call	_malloc

	;	check malloc return

	cmp		rax, 0
	je		_end_null

	;	ft_memcpy

	pop		rdx
	add		rdx, 1
	pop		rsi
	mov		rdi, rax
	call	_ft_memcpy

_end:

	pop		rbp
	ret

_end_null:

	mov		rax, 0
	pop		rbp
	ret
