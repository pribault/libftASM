; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcat.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/10 21:17:47 by pribault          #+#    #+#              ;
;    Updated: 2018/02/16 16:13:28 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text

extern	ft_strlen
extern	ft_memcpy

global	ft_strcat

;	char	*ft_strcat(char *dest, const char *src)

ft_strcat:

	push	rdi

	call	ft_strlen

	sub		rdi, 1
	push	rdi

	mov		rdi, rsi

	call	ft_strlen

	mov		rdx, rax
	add		rdx, 1
	pop		rdi

	call	ft_memcpy

_end:

	pop		rdi
	mov		rax, rdi
	ret

_end_null:

	mov		rax, rdi
	ret
