; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_puts.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/10 16:07:46 by pribault          #+#    #+#              ;
;    Updated: 2018/02/12 12:39:23 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

%define SYSCALL(x)	x
%define WRITE		1
%define STDOUT		1

section	.data

	new_line	db	10

section	.text

global	ft_puts

extern	ft_strlen

ft_puts:

	mov		rbx, rdi

	call	ft_strlen

	mov		rsi, rbx
	mov		rdx, rax
	mov		rax, SYSCALL(WRITE)
	mov		rdi, STDOUT
	syscall
	mov		rax, SYSCALL(WRITE)
	lea		rsi, [rel new_line]
	mov		rdx, 1
	syscall
	ret
