; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_whatis.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/14 13:05:24 by pribault          #+#    #+#              ;
;    Updated: 2018/02/14 13:05:55 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

%define BYTE(x)	(1 << x)

%define ISASCII	BYTE(0)
%define ISALNUM	BYTE(3)
%define ISALPHA	BYTE(10)
%define ISDIGIT	BYTE(11)
%define ISPRINT	BYTE(14)

section	.text

extern	ft_isalnum
extern	ft_isalpha
extern	ft_isascii
extern	ft_isdigit
extern	ft_isprint

global	ft_whatis

	;	int		ft_whatis(int c)

ft_whatis:

	mov		esi, 0
	call	ft_isalnum
	or		esi, eax
	call	ft_isalpha
	or		esi, eax
	call	ft_isascii
	or		esi, eax
	call	ft_isdigit
	or		esi, eax
	call	ft_isprint
	or		eax, esi
	ret
