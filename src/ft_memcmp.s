; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memcmp.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/11 16:12:42 by pribault          #+#    #+#              ;
;    Updated: 2018/02/11 20:37:28 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section	.text

global	_ft_memcmp

	;	int	memcmp(const void *s1, const void *s2, size_t n)

_ft_memcmp:

	mov		rax, rdx
	mov		rdx, 0
	mov		rcx, 8
	div		cx
	cmp		rax, 0
	je		_cmp_8

_cmp_64:

	mov		rcx, rax
	repe	cmpsq
	sub		rdi, 8
	sub		rsi, 8
	add		rdx, 8

_cmp_8:

	mov		rcx, rdx
	rep		cmpsb
	dec		rdi
	dec		rsi

_end:
	mov	rax, 0
	mov	al, byte [rdi]
	mov	rbx, 0
	mov	bl, byte [rsi]
	sub	rax, rbx
	ret
