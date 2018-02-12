; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_toupper.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/10 16:07:46 by pribault          #+#    #+#              ;
;    Updated: 2018/02/12 12:30:36 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section	.text

global	ft_toupper

ft_toupper:
	cmp		edi, 'a'
	jl		_false
	cmp		edi, 'z'
	jg		_false
	mov		eax, edi
	sub		eax, 32
	ret

_false:
	mov		eax, edi
	ret
