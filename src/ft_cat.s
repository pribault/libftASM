; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_cat.s                                           :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/10 16:07:46 by pribault          #+#    #+#              ;
;    Updated: 2018/05/02 18:25:12 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

%define SYSCALL(x)		0x2000000 | x

%define BUFF_SIZE		8192

%define READ			3
%define WRITE			4

%define STDOUT			1

section	.text

extern	_ft_bzero
extern	_mmap

global	_ft_cat

	;	ssize_t		read(int fildes, void *buf, size_t nbyte);

	;	ssize_t		write(int fildes, const void *buf, size_t nbyte);

	;	void		ft_cat(int fd);

_ft_cat:

	push	rbp
	mov		rbp, rsp

	;	allocate buffer

	sub		rsp, BUFF_SIZE

	;	set buffer as seconds parameter

	mov		rsi, rsp

_read:

	;	read

	mov		rdx, BUFF_SIZE
	mov		rax, SYSCALL(READ)
	syscall

	;	if read reach end of file or encounter an error go to _end

	cmp		rax, 0
	je		_end
	cmp		rax, -1
	je		_end

_write:

	;	write

	push	rdi

	mov		rdi, STDOUT
	mov		rdx, rax
	mov		rax, SYSCALL(WRITE)
	syscall

	pop		rdi

	jmp		_read


_end:

	mov		rsp, rbp
	pop		rbp
	ret
