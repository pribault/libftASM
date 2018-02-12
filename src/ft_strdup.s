; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/10 21:17:36 by pribault          #+#    #+#              ;
;    Updated: 2018/02/12 12:31:03 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text

extern	malloc
extern	ft_strlen
extern	ft_memcpy

global ft_strdup

	;	char	*ft_strdup(const char *s);

ft_strdup:

_start:

	push	rbp

	;	get the string len

	push	rdi
	
	call	ft_strlen

	mov		rdi, rax
	inc		rdi
	push	rdi
	call	malloc

	;	check malloc return

	cmp		rax, 0
	je		_end_malloc_null

	;	ft_memcpy

	pop		rdx
	pop		rsi
	mov		rdi, rax
	call	ft_memcpy

_end:

	pop		rbp
	ret

_end_malloc_null:
	add		rsp, 16
	mov		rax, 0
	pop		rbp
	ret

_end_null:

	mov		rax, 0
	pop		rbp
	ret
