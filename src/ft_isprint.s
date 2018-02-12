; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isprint.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/10 16:07:46 by pribault          #+#    #+#              ;
;    Updated: 2018/02/12 12:29:37 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section	.text

global	ft_isprint

	;	int		ft_isprint(int c)

ft_isprint:
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
