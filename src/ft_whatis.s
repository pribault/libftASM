; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_whatis.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/14 13:05:24 by pribault          #+#    #+#              ;
;    Updated: 2018/02/15 12:53:05 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

%define BYTE(x)	(1 << x)

%define ISASCII		BYTE(0)
%define ISCNTRL		BYTE(1)
%define ISALNUM		BYTE(3)
%define ISUPPER		BYTE(8)
%define ISLOWER		BYTE(9)
%define ISALPHA		BYTE(10)
%define ISDIGIT		BYTE(11)
%define ISXDIGIT	BYTE(12)
%define ISSPACE		BYTE(13)
%define ISPRINT		BYTE(14)
%define ISGRAPH		BYTE(15)

section	.text

extern	ft_isascii
extern	ft_iscntrl
extern	ft_isalnum
extern	ft_isupper
extern	ft_islower
extern	ft_isalpha
extern	ft_isdigit
extern	ft_isxdigit
extern	ft_isspace
extern	ft_isprint
extern	ft_isgraph

global	ft_whatis

	;	int		ft_whatis(int c)

ft_whatis:

	mov		esi, 0
	call	ft_isascii
	or		esi, eax
	call	ft_iscntrl
	or		esi, eax
	call	ft_isalnum
	or		esi, eax
	call	ft_isupper
	or		esi, eax
	call	ft_islower
	or		esi, eax
	call	ft_isalpha
	or		esi, eax
	call	ft_isdigit
	or		esi, eax
	call	ft_isxdigit
	or		esi, eax
	call	ft_isspace
	or		esi, eax
	call	ft_isprint
	or		esi, eax
	call	ft_isgraph
	or		eax, esi

	ret
