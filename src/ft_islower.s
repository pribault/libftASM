; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_islower.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/14 13:16:43 by pribault          #+#    #+#              ;
;    Updated: 2018/02/17 12:50:00 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section	.text

global	_ft_islower

	;	int		ft_islower(int c)

_ft_islower:

	cmp		edi, 'a'
	jl		_false
	cmp		edi, 'z'
	jg		_false

_true:

	mov		eax, 1
	ret

_false:

	mov		eax, 0
	ret
