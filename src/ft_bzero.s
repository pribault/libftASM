section .text

extern ft_memset

global ft_bzero

;	void	ft_bzero(void *s, size_t n)

ft_bzero:

_init:

	;	pushs

	push	rsi
	push	rdx
	push	rax

	;	setting registers and calling ft_memset

	mov		rdx, rsi
	mov		rsi, 0

	call	ft_memset

	;	popping registers (rax too to overwrite return of ft_memset)

	pop		rax
	pop		rdx
	pop		rsi

	ret
