section	.text

global	_ft_toupper

_ft_toupper:
	cmp		edi, 'a'
	jl		_false
	cmp		edi, 'z'
	jg		_false
	mov		eax, edi
	sub		eax, 32
	ret

_false:
	mov		eax, edi
	ret
