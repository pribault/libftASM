section .text

global ft_strlen

;	size_t	ft_strlen(const char *s)

ft_strlen:

	;	if null return 0

	cmp		rdi, 0
	je		_null

	;	pushs

	push	rdi
	push	rsi
	push	rcx

	;	assign to rcx uint64_t max value

	mov		rcx, 0xffffffffffffffff

	;	assign to al '\0' value

	mov		al, 0

	;	clear flag

	cld

	;	iterate

	repne	scasb

	;	substract 1 to get the address of the last character and not \0

	sub		rdi, 1

	;	move to register that will be returned the final value

	mov		rax, rdi

	;	pops

	pop		rcx
	pop		rsi
	pop		rdi

	;	return the difference between end and start string pointer

	sub		rax, rdi
	ret

_null:
	mov	rax, 0
	ret
