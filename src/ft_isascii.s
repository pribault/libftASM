section	.text

global	_ft_isascii

	;	int		ft_isascii(int c);

_ft_isascii:
	cmp		edi, 128
	jl		_true

_false:
	mov		eax, 0
	ret

_true:
	mov		eax, 1
	ret
