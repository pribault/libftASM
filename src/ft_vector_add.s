%define SYSCALL(x)		x
%define MMAP			9

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

global	ft_vector_add

	;	int		ft_vector_add(size_t type);

ft_vector_add:



_end_fail:

	mov		rax, 1
	ret

_end:

	mov		rax, 0
	ret
