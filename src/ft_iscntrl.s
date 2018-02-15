; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_iscntrl.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/14 13:15:13 by pribault          #+#    #+#              ;
;    Updated: 2018/02/15 10:33:51 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section	.text

global	ft_iscntrl

	;	int		ft_iscntrl(int c)

ft_iscntrl:

	cmp		edi, 32
	jl		_true
	cmp		edi, 127
	je		_true

	mov		eax, 0
	ret

_true:

	mov		eax, 2
	ret
