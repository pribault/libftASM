section	.text

global	_ft_tolower

_ft_tolower:
	cmp		edi, 'A'
	jl		_false
	cmp		edi, 'Z'
	jg		_false
	mov		eax, edi
	add		eax, 32
	ret

_false:
	mov		eax, edi
	ret
