; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcmp.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/11 16:26:24 by pribault          #+#    #+#              ;
;    Updated: 2018/02/11 16:35:20 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section	.text

extern	_ft_strlen
extern	_ft_memcmp

global	_ft_strcmp

	;	int	ft_strcmp(const char *s1, const char *s2)

_ft_strcmp:

	call	_ft_strlen
	mov		rdx, rax

	;	xor swap

	xor		rdi, rsi
	xor		rsi, rdi
	xor		rdi, rsi

	call	_ft_strlen

	cmp		rax, rdx
	jle		_compare
	mov		rdx, rax

_compare:

	inc		rdx

	xor		rdi, rsi
	xor		rsi, rdi
	xor		rdi, rsi

	call	_ft_memcmp
	ret
