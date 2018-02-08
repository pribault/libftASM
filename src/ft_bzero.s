section .text

extern ft_memset

global ft_bzero

;	void	ft_bzero(void *s, size_t n)

ft_bzero:

_init:

	;	setting registers and calling ft_memset

	mov		rdx, rsi
	mov		rsi, 0

	call	ft_memset

	ret
