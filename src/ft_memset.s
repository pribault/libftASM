; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memset.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/10 20:38:39 by pribault          #+#    #+#              ;
;    Updated: 2018/02/12 12:29:57 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text

global	ft_memset

	;	void	*ft_memset(void *s, int c, size_t n);

ft_memset:

	push	rdi

	;	division

	mov		rax, rdx
	mov		rdx, 0
	mov		rcx, 8
	div		rcx

_copy_64:

	cmp		rax, 0
	je		_copy_8

	;	set the 8 bytes

	mov		rcx, rsi
	mov		ch, cl
	mov		bx, cx
	sal		ebx, 16
	add		bx, cx
	mov		ecx, ebx
	sal		rbx, 32
	add		rbx, rcx

	;	iterate by packets of 8 bytes

	mov		rcx, rax
	mov		rax, rbx
	rep		stosq

_copy_8:

	;	iterate byte per byte

	mov		rcx, rdx
	rep		stosb

_end:

	;	return s value

	pop		rax
	ret
