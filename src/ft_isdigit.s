; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isdigit.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/10 16:07:46 by pribault          #+#    #+#              ;
;    Updated: 2018/02/12 12:29:31 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text

global	ft_isdigit

	;	int	ft_isdigit(int c)

ft_isdigit:

	cmp		edi, '0'
	jl		_false
	cmp		edi, '9'
	jg		_false

_true:
	mov		eax, 1
	ret

_false:
	mov		eax, 0
	ret
