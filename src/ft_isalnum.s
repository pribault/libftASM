section .text

global	ft_isalnum

ft_isalnum:

_ft_isalpha:

_maj_1:
	cmp		edi, 'A'
	jge		_maj_2
	jmp		_min_1

_maj_2:
	cmp		edi, 'Z'
	jle		_true
	jmp		_min_1

_min_1:
	cmp		edi, 'a'
	jge		_min_2
	jmp		_ft_isdigit

_min_2:
	cmp		edi, 'z'
	jle		_true
	jmp		_ft_isdigit

_ft_isdigit:

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
