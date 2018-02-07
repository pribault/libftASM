/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 16:20:27 by pribault          #+#    #+#             */
/*   Updated: 2018/02/07 18:16:00 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_asm.h"
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>

void	test(long a)
{
	printf("receiving %ld\n", a);
}

void	memdump(void *ptr, size_t size)
{
	static unsigned char	min = 238;
	static unsigned char	max = 255;
	unsigned char			c;

	printf("\033[0m");
	for (size_t i = 0; i < size; i++)
	{
		c = *(unsigned char*)(ptr + i);
		printf("\033[38;5;%um%.2hhx ", min + (c / (max - min)), c);
	}
	printf("\n");
}

void	test_ft_bzero(void)
{
	//	127 is a power of 2 - 1, so bzero need to pass by all the whiles
	char		a[127];

	printf("\033[0m\033[1m___ft_bzero___\n\n");

	printf("\033[0mhere is a big array of size %lu:\n", sizeof(a));
	memset(&a, 42, sizeof(a));
	memdump(&a, sizeof(a));
	ft_bzero(&a, sizeof(a));
	printf("\033[0m\nbzero !\n");
	memdump(&a, sizeof(a));

	printf("\033[1m\n______________\n\n");
}

void	test_ft_strlen(void)
{
	char	*a = "hello I'm a string :D";
	char	*b = "";
	char	*c = NULL;
	char	*d = "aaa";

	printf("\033[0m\033[1m___ft_strlen___\n\n");

	printf("\033[0mft_strlen(%s)=%lu\n", a, ft_strlen(a));
	printf("\033[0mft_strlen(%s)=%lu\n", b, ft_strlen(b));
	printf("\033[0mft_strlen(%s)=%lu\n", c, ft_strlen(c));
	printf("\033[0mft_strlen(%s)=%lu\n", d, ft_strlen(d));

	printf("\033[1m\n______________\n\n");
}

void	test_ft_memcpy(void)
{
	char	a[127];
	char	b[sizeof(a)];

	printf("\033[0m\033[1m___ft_memcpy___\n\n");

	memset(&a, 0xab, sizeof(a));
	memset(&b, 0x42, sizeof(b));
	b[41] = 0x88;
	b[42] = 0x88;
	b[43] = 0x88;
	printf("\033[0m\033[4marray a:\n");
	memdump(&a, sizeof(a));
	printf("\033[0m\033[4m\narray b:\n");
	memdump(&b, sizeof(b));
	ft_memcpy(&a, &b, sizeof(a));
	printf("\033[0m\nmemcpy !\n\n");
	printf("\033[0m\033[4marray a:\n");
	memdump(&a, sizeof(a));
	printf("\033[0m\033[4m\narray b:\n");
	memdump(&b, sizeof(b));

	printf("\033[1m\n______________\n\n");
}

void	test_ft_strcat(void)
{
	printf("\033[0m\033[1m___ft_strcat___\n\n");

	printf("\033[0mft_strcat=%p\n", ft_strcat(NULL, NULL));

	printf("\033[1m\n______________\n\n");
}

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		test_ft_bzero();
		test_ft_strlen();
		test_ft_memcpy();
		test_ft_strcat();
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		if (!strcmp(argv[i], "ft_bzero"))
			test_ft_bzero();
		else if (!strcmp(argv[i], "ft_strlen"))
			test_ft_strlen();
		else if (!strcmp(argv[i], "ft_memcpy"))
			test_ft_memcpy();
		else if (!strcmp(argv[i], "ft_strcat"))
			test_ft_strcat();
		else
			printf("unknown function %s\n", argv[i]);
	}
	return (0);
}