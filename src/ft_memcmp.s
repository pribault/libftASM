; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memcmp.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/12 19:41:43 by pribault          #+#    #+#              ;
;    Updated: 2018/02/17 12:54:10 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section	.text

global	_ft_memcmp

	;	int	memcmp(const void *s1, const void *s2, size_t n)

_ft_memcmp:

	mov		rax, rdx
	mov		rdx, 0
	mov		rcx, 8
	div		rcx

_cmp_64:

	mov		rcx, rax

	repe	cmpsq

	jne		_cmp_8_init
	jmp		_cmp_8

_cmp_8_init:

	add		rdx, 8
	sub		rdi, 8
	sub		rsi, 8

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