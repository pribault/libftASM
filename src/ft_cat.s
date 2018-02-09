%define STRUCT_STAT_SIZE	144
%define SIZE_OFFSET			96
%define MACHO_SYSCALL(x)	0x2000000 | x
%define WRITE				4
%define FSTAT				189
%define MMAP				197
%define MUNMAP				73

section	.text

global	_ft_cat

	;	int		fstat(int fildes, struct stat *buf);

	;	void	*mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset);

	;	ssize_t	write(int fildes, const void *buf, size_t nbyte);

	;	void	ft_cat(int fd);

_ft_cat:
	

_end:
	ret
