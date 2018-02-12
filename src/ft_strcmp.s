; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcmp.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/11 16:26:24 by pribault          #+#    #+#              ;
;    Updated: 2018/02/12 12:30:15 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section	.text

extern	ft_strlen
extern	ft_memcmp

global	ft_strcmp

	;	int	ft_strcmp(const char *s1, const char *s2)

ft_strcmp:

	call	ft_strlen
	mov		rdx, rax

	;	xor swap

	xor		rdi, rsi
	xor		rsi, rdi
	xor		rdi, rsi

	call	ft_strlen

	cmp		rax, rdx
	jle		_compare
	mov		rdx, rax

_compare:

	inc		rdx

	xor		rdi, rsi
	xor		rsi, rdi
	xor		rdi, rsi

	call	ft_memcmp
	ret
