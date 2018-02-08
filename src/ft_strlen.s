%define UINT64_MAX	0xffffffffffffffff

section .text

global ft_strlen

;	size_t	ft_strlen(const char *s)

ft_strlen:

	;	check pointer

	cmp		rdi, 0
	je		_null

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
