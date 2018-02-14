; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_tolower.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/11 11:56:57 by pribault          #+#    #+#              ;
;    Updated: 2018/02/13 17:15:48 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section	.text

global	ft_tolower

	;	int		ft_toupper(int c)

ft_tolower:

	cmp		rdi, 'A'
	jl		_false
	cmp		rdi, 'Z'
	jg		_false
	mov		rax, rdi
	add		rax, 32
	ret

_false:

	mov		rax, rdi
	ret
