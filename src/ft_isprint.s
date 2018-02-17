; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isprint.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/10 16:07:46 by pribault          #+#    #+#              ;
;    Updated: 2018/02/17 12:50:03 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section	.text

global	_ft_isprint

	;	int		ft_isprint(int c)

_ft_isprint:

	cmp		edi, 32
	jl		_false
	cmp		edi, 126
	jg		_false

_true:

	mov		eax, 1
	ret

_false:

	mov		eax, 0
	ret
