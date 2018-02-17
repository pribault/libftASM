; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isxdigit.s                                      :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/14 13:17:45 by pribault          #+#    #+#              ;
;    Updated: 2018/02/17 12:50:12 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section	.text

global	_ft_isxdigit

	;	int		ft_isxdigit(int c)

_ft_isxdigit:

	cmp		edi, '0'
	jl		_false
	cmp		edi, '9'
	jle		_true

	cmp		edi, 'A'
	jl		_false
	cmp		edi, 'F'
	jle		_true

	cmp		edi, 'a'
	jl		_false
	cmp		edi, 'f'
	jg		_false

_true:

	mov		eax, 1
	ret

_false:

	mov		eax, 0
	ret
