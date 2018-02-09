section .text

global	ft_isalpha

	;	int	ft_isalpha(int c)

ft_isalpha:

_maj_1:
	cmp		edi, 'A'
	jge		_maj_2

_min_1:
	cmp		edi, 'a'
	jl		_false

_min_2:
	cmp		edi, 'z'
	jle		_true
	jmp		_false

_maj_2:
	cmp		edi, 'Z'
	jle		_true
	jmp		_min_1

_true:
	mov		eax, 1
	ret

_false:
	mov		eax, 0
	ret
