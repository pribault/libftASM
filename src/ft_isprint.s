section	.text

global	ft_isprint

	;	int		ft_isprint(int c)

ft_isprint:
	cmp		edi, 32
	jl		_false
	cmp		edi, 126
	jg		_false

_true:
	mov		eax, 1
	ret

_false:
	mov		eax, 0
	ret
