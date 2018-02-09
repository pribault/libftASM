%define WRITE	4
%define STDOUT	1

section	.data

	new_line	db	10

section	.text

global	ft_puts

extern	ft_strlen

ft_puts:

	mov		rbx, rdi

	call	ft_strlen

	mov		rcx, rbx
	mov		rdx, rax
	mov		rax, WRITE
	mov		rbx, STDOUT
	int		0x80
	mov		rax, WRITE
	mov		rcx, new_line
	mov		rdx, 1
	int		0x80
