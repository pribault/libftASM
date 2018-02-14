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

extern	malloc

global	ft_vector_new

	;	void	*ft_vector_new(size_t type);

ft_vector_new:

	mov		rax, 0

_end:

	ret
