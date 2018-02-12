; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/10 19:24:43 by pribault          #+#    #+#              ;
;    Updated: 2018/02/12 12:29:50 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text

global	ft_memcpy

	;	void	*ft_memcpy(void *dest, const void *src, size_t n);

ft_memcpy:

_start:

	push	rdi

_div:

	;	divide n by 8 to get quotient and reminder:
	
	;	the quotient is the number of packets of 8 bytes
	;	and is used to copy faster.

	mov		rax, rdx
	mov		rdx, 0
	mov		rcx, 8
	div		cx

_copy_64:

	;	copy by 8 bytes

	mov		rcx, rax
	rep		movsq

_copy_8:

	;	copy the last bytes (max 7 so don't need to optimize anymore)

	mov		rcx, rdx
	rep		movsb

_end:

	pop		rax
	ret
