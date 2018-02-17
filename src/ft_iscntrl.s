; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_iscntrl.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/14 13:15:13 by pribault          #+#    #+#              ;
;    Updated: 2018/02/17 12:49:50 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section	.text

global	_ft_iscntrl

	;	int		ft_iscntrl(int c)

_ft_iscntrl:

	cmp		edi, 32
	jl		_true
	cmp		edi, 127
	je		_true

	mov		eax, 0
	ret

_true:

	mov		eax, 1
	ret
