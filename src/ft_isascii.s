; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isascii.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/10 20:34:24 by pribault          #+#    #+#              ;
;    Updated: 2018/02/12 12:29:16 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section	.text

global	ft_isascii

	;	int		ft_isascii(int c);

ft_isascii:
	cmp		edi, 0
	jl		_false
	cmp		edi, 128
	jl		_true

_false:
	mov		eax, 0
	ret

_true:
	mov		eax, 1
	ret
