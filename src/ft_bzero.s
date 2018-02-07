section .data

section .text

extern printf

global ft_bzero

ft_bzero:

_init:
	;push registers that will be used
	push	rdi
	push	rsi
	push	rdx

	;rsi is the starting address, rdi the max
	add		rsi, rdi

	;
	mov		rdx, rdi

_select_64:
	add		rdx, 7
	cmp		rdx, rsi
	jge		_select_32

_while_64:
	mov		qword [rdi], 0
	add		rdi, 8
	add		rdx, 8
	cmp		rdx, rsi
	jl		_while_64

_select_32:
	sub		rdx, 4
	cmp		rdx, rsi
	jge		_select_16

_while_32:
	mov		dword [rdi], 0
	add		rdi, 4
	add		rdx, 4
	cmp		rdx, rsi
	jl		_while_32

_select_16:
	sub		rdx, 2
	cmp		rdx, rsi
	jge		_select_8

_while_16:
	mov		word [rdi], 0
	add		rdi, 2
	add		rdx, 2
	cmp		rdx, rsi
	jl		_while_16

_select_8:
	cmp		rdi, rsi
	jge		_end

_while_8:
	mov		byte [rdi], 0
	inc		rdi
	cmp		rdi, rsi
	jl		_while_8

_end:
	pop		rdx
	pop		rsi
	pop		rdi
	ret
