%define UINT64_MAX	0xffffffffffffffff

section .text

global	_ft_strlen

	;	size_t	ft_strlen(const char *s)

_ft_strlen:

	;	assignations

	mov		rcx, UINT64_MAX
	mov		al, 0

	;	iterate

	cld
	repne	scasb

	;	compute final value

	mov		rax, rcx
	not		rax
	dec		rax

	ret

_null:

	;	if null return 0

	mov	rax, 0
	ret
