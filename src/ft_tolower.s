; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_tolower.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/11 11:56:57 by pribault          #+#    #+#              ;
;    Updated: 2018/02/12 12:30:33 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section	.text

global	ft_tolower

ft_tolower:
	cmp		edi, 'A'
	jl		_false
	cmp		edi, 'Z'
	jg		_false
	mov		eax, edi
	add		eax, 32
	ret

_false:
	mov		eax, edi
	ret
