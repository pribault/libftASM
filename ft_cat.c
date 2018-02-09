/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 20:44:07 by pribault          #+#    #+#             */
/*   Updated: 2018/02/09 20:53:56 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>

int		main(int argc, char **argv)
{
	struct stat	buff;
	void		*s;
	int			fd;

	fd = -1;
	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) == -1 ||
		fstat(fd, &buff) == -1 || !(s = mmap(NULL, buff.st_size,
		PROT_READ, MAP_FILE | MAP_PRIVATE, fd, 0)))
	{
		if (fd != -1)
			close(fd);
		return (1);
	}
	write(1, s, buff.st_size);
	munmap(s, buff.st_size);
	close(fd);
	return (0);
}
