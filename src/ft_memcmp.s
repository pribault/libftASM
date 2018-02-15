; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memcmp.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/12 19:41:43 by pribault          #+#    #+#              ;
;    Updated: 2018/02/15 17:22:52 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section	.text

global	ft_memcmp

	;	int	memcmp(const void *s1, const void *s2, size_t n)

ft_memcmp:

	mov		eax, 0
	ret