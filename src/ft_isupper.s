; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isupper.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/14 13:16:43 by pribault          #+#    #+#              ;
;    Updated: 2018/02/15 11:02:32 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section	.text

global	ft_isupper

	;	int		ft_isupper(int c)

ft_isupper:

	cmp		edi, 'A'
	jl		_false
	cmp		edi, 'Z'
	jg		_false

_true:

	mov		eax, 256
	ret

_false:

	mov		eax, 0
	ret
