; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcmp.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/11 16:26:24 by pribault          #+#    #+#              ;
;    Updated: 2018/02/12 22:16:42 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section	.text

extern	ft_strlen
extern	ft_memcmp

global	ft_strcmp

	;	int	ft_strcmp(const char *s1, const char *s2)

ft_strcmp:

	mov		rcx, 0
	mov		rax, 0

_compare:

	mov		al, byte [rdi]
	cmp		al, 0
	je		_end
	cmp		byte [rsi], 0
	je		_end
	cmp		al, byte [rsi]
	je		_end
	inc		rdi
	inc		rsi
	jmp		_compare

_end:

	mov		rdi, 0
	mov		dl, byte [rsi]
	sub		rax, rdi
	ret
