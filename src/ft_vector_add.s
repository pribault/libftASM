%define SYSCALL(x)		0x2000000 | x
%define MMAP			197

%define PROT

%define VECTOR_TYPE		0
%define VECTOR_N		8
%define VECTOR_SIZE		16
%define VECTOR_PTR		24

%define SIZEOF_VECTOR	32
%define VECTOR_PAGE		4096

	;	struct:
	;		size_t	type;
	;		size_t	n;
	;		size_t	size;
	;		void	*ptr;

section	.text

global	_ft_vector_add

	;	int		ft_vector_add(t_vector *vector, void *ptr)

_ft_vector_add:

	mov		rax, [rdi + VECTOR_N]
	inc		rax
	mul		qword [rdi + VECTOR_TYPE]
	cmp		rax, [rdi + VECTOR_SIZE]
	jl		_add

	push	rdi
	push	rsi

	mov		rdx, 0
	mov		rsi, VECTOR_PAGE
	div		rsi
	mov		rdx, 0
	mul		rsi
	add		rax, VECTOR_PAGE
	mov		rsi, rax
	mov		rdi, [rdi + VECTOR_PTR]

	pop		rsi
	pop		rdi

_add:

_end_fail:

	mov		rax, 1
	ret

_end:

	mov		rax, 0
	ret
