; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memcmp.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/12 19:41:43 by pribault          #+#    #+#              ;
;    Updated: 2018/02/16 15:48:36 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section	.text

global	ft_memcmp

	;	int	memcmp(const void *s1, const void *s2, size_t n)

ft_memcmp:

	mov		rax, rdx
	mov		rdx, 0
	mov		rcx, 8
	div		rcx

_cmp_64:

	mov		rcx, rax

	repe	cmpsq

	jne		_cmp_16_init
	jmp		_cmp_16

_cmp_16_init:

	add		rdx, 8
	sub		rdi, 8
	sub		rsi, 8

_cmp_16:

	cmp		rdx, 1
	jle		_cmp_8

	cmpsw
	jne		_found_word

	sub		rdx, 2

	jmp		_cmp_16

_found_word:

	mov		rax, 0
	mov		rcx, 0
	mov		ax, [rdi - 2]
	mov		cx, [rsi - 2]
	cmp		al, cl
	jne		_found_byte
	sub		rax, rcx
	ret

_found_byte:

	mov		ah, 0
	mov		ch, 0
	sub		eax, ecx
	ret

_cmp_8:

	mov		rcx, rdx

	repe	cmpsb

	je		_end

_found:

	mov		rcx, 0
	mov		al, [rdi - 1]
	mov		cl, [rsi - 1]
	sub		rax, rcx
	ret

_end:

	mov		eax, 0
	ret