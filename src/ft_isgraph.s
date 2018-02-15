; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isgraph.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/14 13:16:19 by pribault          #+#    #+#              ;
;    Updated: 2018/02/15 10:39:44 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section	.text

global	ft_isgraph

	;	int		ft_isgraph(int c)

ft_isgraph:

	cmp		edi, 32
	jle		_false
	cmp		edi, 126
	jg		_false

_true:

	mov		eax, 32768
	ret

_false:

	mov		eax, 0
	ret
