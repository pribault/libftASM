; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcmp.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/11 16:26:24 by pribault          #+#    #+#              ;
;    Updated: 2018/02/17 12:39:55 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section	.text

global	_ft_strcmp

	;	int	ft_strcmp(const char *s1, const char *s2)

_ft_strcmp:

	mov		rax, 0
	mov		rcx, 0

_compare:

	mov		al, byte [rdi]
	cmp		al, 0
	je		_end_a

	mov		cl, byte [rsi]
	cmp		cl, 0
	je		_end

	cmp		al, cl
	jne		_end

	inc		rdi
	inc		rsi
	jmp		_compare

_end_a:

	mov		cl, byte [rsi]

_end:

	sub		eax, ecx
	ret
