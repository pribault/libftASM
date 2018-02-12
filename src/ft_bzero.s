; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_bzero.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/10 16:07:46 by pribault          #+#    #+#              ;
;    Updated: 2018/02/12 12:28:53 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text

extern	ft_memset

global	ft_bzero

;	void	ft_bzero(void *s, size_t n)

ft_bzero:

_init:

	;	setting registers and calling ft_memset

	mov		rdx, rsi
	mov		rsi, 0

	call	ft_memset

	ret
