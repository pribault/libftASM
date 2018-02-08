section .text

extern malloc
extern ft_strlen
extern ft_memcpy

global ft_strdup

;	char	*ft_strdup(const char *s);

ft_strdup:

	;	pushs

	push	rdi
	push	rsi
	push	rdx

_start:

	;	check the string

	cmp		rdi, 0
	je		_end_null

	;	get the string len
	
	call	ft_strlen

	push	rdi
	mov		rdi, rax
	push	rdi
	call	malloc

	;	check malloc return

	cmp		rax, 0
	je		_end

	;	ft_memcpy

	pop		rdx
	add		rdx, 1
	pop		rsi
	mov		rdi, rax
	call	ft_memcpy

_end:

	;	pops

	pop		rdx
	pop		rsi
	pop		rdi

	ret

_end_null:

	;	pops

	pop		rdx
	pop		rsi
	pop		rdi

	mov		rax, 0
	ret
