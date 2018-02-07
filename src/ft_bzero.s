section .text

extern printf

global ft_bzero

;	void	ft_bzero(void *s, size_t n)

ft_bzero:

_init:

	;	saving registers that will be used
	push	rdi
	push	rsi
	push	rdx

	;	rsi is the starting address, rdi the max
	add		rsi, rdi

	;	rdx is the end address used to know
	;	if we can set multiple bits at a time
	mov		rdx, rdi

_select_64:
	add		rdx, 8
	cmp		rdx, rsi

	;	jump if addr + 8 is superior to address max
	;	(if we cannot set 8 bytes at once)
	jg		_select_32

_while_64:

	;	set 8 bytes to zero
	mov		qword [rdi], 0
	add		rdi, 8
	add		rdx, 8
	cmp		rdx, rsi

	;	jump if we can still set 8 bytes to zero
	jl		_while_64

_select_32:
	sub		rdx, 4
	cmp		rdx, rsi

	;	jump if addr + 4 is superior to address max
	;	(if we cannot set 4 bytes at once)
	jg		_select_16

_while_32:

	;	set 4 bytes to zero
	mov		dword [rdi], 0
	add		rdi, 4
	add		rdx, 4
	cmp		rdx, rsi

	;	jump if we can still set 4 bytes to zero
	jl		_while_32

_select_16:
	sub		rdx, 2
	cmp		rdx, rsi

	;	jump if addr + 2 is superior to address max
	;	(if we cannot set 2 bytes at once)
	jg		_select_8

_while_16:

	;	set 2 bytes to zero
	mov		word [rdi], 0
	add		rdi, 2
	add		rdx, 2
	cmp		rdx, rsi

	;	jump if we can still set 2 bytes to zero
	jl		_while_16

_select_8:
	cmp		rdi, rsi
	;	jump if addr is superior or equal to address max
	;	(if we cannot set one byte)
	jge		_end

_while_8:

	;	set 1 byte to zero
	mov		byte [rdi], 0
	inc		rdi
	cmp		rdi, rsi

	;	jump if we can still set 1 bytes to zero
	jl		_while_8

_end:
	;	pops
	pop		rdx
	pop		rsi
	pop		rdi

	ret
