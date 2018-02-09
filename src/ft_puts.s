%define SYSCALL(x)	0x2000000 | x
%define WRITE		4
%define STDOUT		1

section	.data

	new_line	db	10

section	.text

global	_ft_puts

extern	_ft_strlen

_ft_puts:

	mov		rbx, rdi

	call	_ft_strlen

	mov		rsi, rbx
	mov		rdx, rax
	mov		rax, SYSCALL(WRITE)
	mov		rdi, STDOUT
	syscall
	mov		rax, SYSCALL(WRITE)
	lea		rsi, [rel new_line]
	mov		rdx, 1
	syscall
	ret
