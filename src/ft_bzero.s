section .text

extern	_ft_memset

global	_ft_bzero

;	void	ft_bzero(void *s, size_t n)

_ft_bzero:

_init:

	;	setting registers and calling ft_memset

	mov		rdx, rsi
	mov		rsi, 0

	call	_ft_memset

	ret
