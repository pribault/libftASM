; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isblank.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/14 13:14:44 by pribault          #+#    #+#              ;
;    Updated: 2018/02/14 13:27:56 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section	.text

global	ft_isblank

	;	int		ft_isblank(int c)

ft_isblank:

	cmp		edi, ' '
	je		_true
	cmp		edi, '	'
	je		_true

_false:

	mov		eax, 0
	ret

_true:

	mov		eax, 1
	ret
