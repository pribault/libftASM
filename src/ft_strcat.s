section .text

extern	ft_strlen
extern	ft_memcpy

global	ft_strcat

;	char	*ft_strcat(char *dest, const char *src)

ft_strcat:

	cmp		rdi, 0
	je		_end_null
	cmp		rsi, 0
	je		_end_null

	push	rdi

	call	ft_strlen

	sub		rdi, 1
	push	rdi

	mov		rdi, rsi

	call	ft_strlen

	mov		rdx, rax
	add		rdx, 1
	pop		rdi

	call	ft_memcpy

_end:

	pop		rdi
	mov		rax, rdi
	ret

_end_null:

	mov		rax, rdi
	ret
