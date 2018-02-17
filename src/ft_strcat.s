; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcat.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/10 21:17:47 by pribault          #+#    #+#              ;
;    Updated: 2018/02/17 12:39:39 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text

extern	_ft_strlen
extern	_ft_memcpy

global	_ft_strcat

;	char	*ft_strcat(char *dest, const char *src)

_ft_strcat:

	push	rdi

	call	_ft_strlen

	sub		rdi, 1
	push	rdi

	mov		rdi, rsi

	call	_ft_strlen

	mov		rdx, rax
	add		rdx, 1
	pop		rdi

	call	_ft_memcpy

_end:

	pop		rdi
	mov		rax, rdi
	ret

_end_null:

	mov		rax, rdi
	ret
