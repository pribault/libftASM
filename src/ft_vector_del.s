%define SYSCALL(x)		0x2000000 | x
%define MUNMAP			73

%define VECTOR_TYPE		0
%define VECTOR_N		8
%define VECTOR_SIZE		16
%define VECTOR_PTR		24

%define SIZEOF_VECTOR	32

	;	struct:
	;		size_t	type;
	;		size_t	n;
	;		size_t	size;
	;		void	*ptr;

section	.text

global	_ft_vector_del

	;	void	ft_vector_del(t_vector *vector)

_ft_vector_del:

	cmp		qword [rdi + VECTOR_SIZE], 0
	je		_clean

	push	rdi

	mov		rsi, [rdi + VECTOR_SIZE]
	mov		rdi, [rdi + VECTOR_PTR]
	mov		rax, SYSCALL(MUNMAP)
	syscall

	pop		rdi

_clean:

	mov		qword [rdi + VECTOR_N], 0
	mov		qword [rdi + VECTOR_SIZE], 0
	mov		qword [rdi + VECTOR_PTR], 0
	ret
