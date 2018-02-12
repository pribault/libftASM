; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memcmp.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/12 19:41:43 by pribault          #+#    #+#              ;
;    Updated: 2018/02/12 22:22:21 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section	.text

global	ft_memcmp

	;	int	memcmp(const void *s1, const void *s2, size_t n)

ft_memcmp:

	mov		rax, rdx
	mov		rdx, 0
	mov		rcx, 8
	div		cx

_cmp_64:

	cmp		rax, 0
	je		_init_cmp_8
	mov		rcx, [rdi]
	cmp		rcx, [rsi]
	je		_init_cmp_8
	dec		rax
	add		rdi, 8
	add		rsi, 8
	jmp		_cmp_64

_init_cmp_8:

	mov		rcx, 0

_cmp_8:

	cmp		rdx, 0
	je		_end
	mov		cl, [rdi]
	cmp		cl, [rsi]
	je		_end_found
	dec		rdx
	inc		rdi
	inc		rsi
	jmp		_cmp_8

_end:

	mov		rax, 0
	ret

_end_found:

	mov		rax, rcx
	mov		cl, [rsi]
	sub		rax, rcx
	ret
