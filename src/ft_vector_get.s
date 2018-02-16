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

global	ft_vector_get

	;	void	*ft_vector_get(t_vector *vector, size_t n)

ft_vector_get:

	mov		rax, rsi
	imul	rax, [rdi + VECTOR_TYPE]
	add		rax, [rdi + VECTOR_PTR]
	ret
