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

global	ft_vector_init

	;	void	ft_vector_init(t_vector *vector, size_t type)

ft_vector_init:

	mov		[rdi + VECTOR_TYPE], rsi
	mov		qword [rdi + VECTOR_N], 0
	mov		qword [rdi + VECTOR_SIZE], 0
	mov		qword [rdi + VECTOR_PTR], 0

_end:

	ret
