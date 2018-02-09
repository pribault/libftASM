section .text

global	ft_isdigit

	;	int	ft_isdigit(int c)

ft_isdigit:

	cmp		edi, '0'
	jl		_false
	cmp		edi, '9'
	jg		_false

_true:
	mov		eax, 1
	ret

_false:
	mov		eax, 0
	ret
