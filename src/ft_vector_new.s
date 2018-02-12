%define SYSCALL(x)	x
%define MMAP		9

	;	struct:
	;		size_t	type;
	;		size_t	n;
	;		size_t	size;
	;		void	*ptr;

section	.text

global	ft_vector_new

	;	void	*ft_vector_new(size_t type);

ft_vector_new:

_end_null:

	mov		rax, 0
	ret
