; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_swap.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/11 16:34:41 by pribault          #+#    #+#              ;
;    Updated: 2018/02/11 19:37:34 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section	.text

global	_ft_swap

	;	void	ft_swap(void *a, void *b, size_t n)

_ft_swap:
	
	mov		rax, rdx
	mov		rdx, 0
	mov		rcx, 8
	div		cx

_swap_64:

	cmp		rax, 0
	je		_swap_8

	mov		rcx, qword [rdi]
	xor		rcx, qword [rsi]
	xor		qword [rsi], rcx
	xor		rcx, qword [rsi]
	mov		qword [rdi], rcx

	add		rdi, 8
	add		rsi, 8
	dec		rax

	jmp		_swap_64

_swap_8:

	cmp		rdx, 0
	je		_end

	mov		cl, byte [rdi]
	xor		cl, byte [rsi]
	xor		byte [rsi], cl
	xor		cl, byte [rsi]
	mov		byte [rdi], cl

	inc		rdi
	inc		rsi
	dec		rdx
	jmp		_swap_8

_end:

	ret
