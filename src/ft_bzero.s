; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_bzero.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/10 16:07:46 by pribault          #+#    #+#              ;
;    Updated: 2018/02/14 08:50:39 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text

extern	ft_memset

global	ft_bzero

;	void	ft_bzero(void *s, size_t n)

ft_bzero:

	;	division

	mov		rax, rsi
	mov		rdx, 0
	mov		rcx, 8
	div		rcx

_copy_64:

	cmp		rax, 0
	je		_copy_8

	;	iterate by packets of 8 bytes

	mov		rcx, rax
	mov		rax, 0
	rep		stosq

_copy_8:

	;	iterate byte per byte

	mov		rcx, rdx
	rep		stosb

_end:

	ret
