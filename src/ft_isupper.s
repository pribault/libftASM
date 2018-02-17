; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isupper.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/14 13:16:43 by pribault          #+#    #+#              ;
;    Updated: 2018/02/17 12:50:09 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section	.text

global	_ft_isupper

	;	int		ft_isupper(int c)

_ft_isupper:

	cmp		edi, 'A'
	jl		_false
	cmp		edi, 'Z'
	jg		_false

_true:

	mov		eax, 1
	ret

_false:

	mov		eax, 0
	ret
