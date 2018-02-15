; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isspace.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/14 13:17:31 by pribault          #+#    #+#              ;
;    Updated: 2018/02/15 12:33:02 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section	.text

global	ft_isspace

	;	int		ft_isspace(int c)

ft_isspace:

	cmp		edi, 9
	jl		_false
	cmp		edi, 13
	jle		_true
	cmp		edi, 32
	jne		_false

_true:

	mov		eax, 8192
	ret

_false:

	mov		eax, 0
	ret
