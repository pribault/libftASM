; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_cat.s                                           :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: pribault <pribault@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2018/02/10 16:07:46 by pribault          #+#    #+#              ;
;    Updated: 2018/02/11 16:34:47 by pribault         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

%define STRUCT_STAT_SIZE	144
%define SIZE_OFFSET			96

%define MACHO_SYSCALL(x)	0x2000000 | x

%define WRITE				4
%define FSTAT				339
%define MMAP				197
%define MUNMAP				73

%define PROT				0x01
%define MAP					0x0002

%define STDOUT				1

section	.text

extern	_mmap

extern	_ft_bzero

global	_ft_cat

	;	int		fstat(int fildes, struct stat *buf);

	;	void	*mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset);

	;	ssize_t	write(int fildes, const void *buf, size_t nbyte);

	;	void	ft_cat(int fd);

_ft_cat:

	;	allocate sizeof(struct stat) on stack

	push	rbp
	mov		rbp, rsp
	sub		rsp, STRUCT_STAT_SIZE

	;	call fstat

	mov		rsi, rsp
	mov		rax, MACHO_SYSCALL(FSTAT)
	syscall

	;	check ftstat return

	cmp		rax, -1
	je		_end

	;	call mmap

	mov		r8, rdi
	mov		rdi, 0
	mov		rsi, qword [rsp + SIZE_OFFSET]
	mov		rdx, PROT
	mov		rcx, MAP
	mov		r9, 0
	mov		rax, MACHO_SYSCALL(MMAP)
	call	_mmap

	;	check mmap return

	cmp		rax, 0
	je		_end

	;	write to stdout

	mov		rdi, STDOUT
	mov		rsi, rax
	mov		rdx, qword [rsp + SIZE_OFFSET]
	mov		rax, MACHO_SYSCALL(WRITE)
	syscall

	;	munmap

	mov		rdi, rsi
	mov		rsi, qword [rsp + SIZE_OFFSET]
	mov		rax, MACHO_SYSCALL(MUNMAP)
	syscall

_end:
	mov		rsp, rbp
	pop		rbp
	ret
