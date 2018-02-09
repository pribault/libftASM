/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 16:20:27 by pribault          #+#    #+#             */
/*   Updated: 2018/02/09 20:39:36 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_asm.h"
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <ctype.h>

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

	printf("\033[0m\033[1m\n______________\n\n");
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

	printf("\033[0m\033[1m\n______________\n\n");
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
	printf("\033[0m\033[4marray a:\033[0m\n");
	memdump(&a, sizeof(a));
	printf("\033[0m\033[4m\narray b:\033[0m\n");
	memdump(&b, sizeof(b));
	ft_memcpy(&a, &b, sizeof(a));
	printf("\033[0m\nmemcpy !\n\n");
	printf("\033[0m\033[4marray a:\033[0m\n");
	memdump(&a, sizeof(a));
	printf("\033[0m\033[4m\narray b:\033[0m\n");
	memdump(&b, sizeof(b));

	printf("\033[0m\033[1m\n______________\n\n");
}

void	test_ft_memset(void)
{
	char	a[127];
	int		c = 42;

	printf("\033[0m\033[1m___ft_memset___\n\n");

	memset(&a, 0, sizeof(a));
	printf("\033[0m\033[4marray a:\033[0m\n");
	memdump(&a, sizeof(a));
	printf("\033[0mft_memset !\n");
	printf("c=%d s=%p p=%p\n", c, &a, ft_memset(&a, c, sizeof(a)));
	printf("\033[0m\033[4marray a:\033[0m\n");
	memdump(&a, sizeof(a));

	printf("\033[0m\033[1m\n______________\n\n");
}

void	test_ft_strdup(void)
{
	char	*a = "Hello I'm a string";
	char	*b = NULL;

	printf("\033[0m\033[1m___ft_strdup___\n\n");

	printf("\033[0mft_strdup(\"%s\")=\"%s\"\n", a, ft_strdup(a));
	printf("\033[0mft_strdup(\"%s\")=\"%s\"\n", b, ft_strdup(b));

	printf("\033[0m\033[1m\n______________\n\n");
}

void	test_ft_strcat(void)
{
	char	*a = malloc(256);
	char	*save_a;
	char	*b = "concatenated :D";

	strcpy(a, "Hello I am ");
	save_a = ft_strdup(a);
	printf("\033[0m\033[1m___ft_strcat___\n\n");

	printf("ft_strcat(\"%s\", \"%s\")=\"%s\"\n", save_a, b, ft_strcat(a, b));

	printf("\033[0m\033[1m\n______________\n\n");
}

void	test_ft_isalpha(void)
{
	unsigned int	isalpha_color = 32;
	unsigned int	ft_isalpha_color = 126;

	printf("\033[0m\033[1m___ft_isalpha___\n\n");

	printf("\033[0m\033[38;5;%umisalpha\n", isalpha_color);
	printf("\033[0m\033[38;5;%umft_isalpha\n\n", ft_isalpha_color);

	for (int i = 0; i < 128; i++)
	{
		printf("\033[0m\033[38;5;%um∎ ", (isalpha(i) == ft_isalpha(i)) ? 46 : 160);
		printf("\033[0m[\033[38;5;%um. %c\033[0m] %d: \033[38;5;%um%d\033[0m\n",
		(isalpha(i)) ? isalpha_color : 7, i, i, ft_isalpha(i) ? ft_isalpha_color : 7, ft_isalpha(i));
	}

	printf("\033[0m\033[1m\n______________\n\n");
}

void	test_ft_isdigit(void)
{
	unsigned int	isdigit_color = 32;
	unsigned int	ft_isdigit_color = 126;

	printf("\033[0m\033[1m___ft_isdigit___\n\n");

	printf("\033[0m\033[38;5;%umisdigit\n", isdigit_color);
	printf("\033[0m\033[38;5;%umft_isdigit\n\n", ft_isdigit_color);

	for (int i = 0; i < 128; i++)
	{
		printf("\033[0m\033[38;5;%um∎ ", (isdigit(i) == ft_isdigit(i)) ? 46 : 160);
		printf("\033[0m[\033[38;5;%um. %c\033[0m] %d: \033[38;5;%um%d\033[0m\n",
		(isdigit(i)) ? isdigit_color : 7, i, i, ft_isdigit(i) ? ft_isdigit_color : 7, ft_isdigit(i));
	}

	printf("\033[0m\033[1m\n______________\n\n");
}

void	test_ft_isalnum(void)
{
	unsigned int	isalnum_color = 32;
	unsigned int	ft_isalnum_color = 126;

	printf("\033[0m\033[1m___ft_isalnum___\n\n");

	printf("\033[0m\033[38;5;%umisalnum\n", isalnum_color);
	printf("\033[0m\033[38;5;%umft_isalnum\n\n", ft_isalnum_color);

	for (int i = 0; i < 128; i++)
	{
		printf("\033[0m\033[38;5;%um∎ ", (isalnum(i) == ft_isalnum(i)) ? 46 : 160);
		printf("\033[0m[\033[38;5;%um. %c\033[0m] %d: \033[38;5;%um%d\033[0m\n",
		(isalnum(i)) ? isalnum_color : 7, i, i, ft_isalnum(i) ? ft_isalnum_color : 7, ft_isalnum(i));
	}

	printf("\033[0m\033[1m\n______________\n\n");
}

void	test_ft_isascii(void)
{
	unsigned int	isascii_color = 32;
	unsigned int	ft_isascii_color = 126;

	printf("\033[0m\033[1m___ft_isascii___\n\n");

	printf("\033[0m\033[38;5;%umisascii\n", isascii_color);
	printf("\033[0m\033[38;5;%umft_isascii\n\n", ft_isascii_color);

	for (int i = 0; i < 256; i++)
	{
		printf("\033[0m\033[38;5;%um∎ ", (isascii(i) == ft_isascii(i)) ? 46 : 160);
		printf("\033[0m[\033[38;5;%um. %c\033[0m] %d: \033[38;5;%um%d\033[0m\n",
		(isascii(i)) ? isascii_color : 7, i, i, ft_isascii(i) ? ft_isascii_color : 7, ft_isascii(i));
	}

	printf("\033[0m\033[1m\n______________\n\n");
}

void	test_ft_isprint(void)
{
	unsigned int	isprint_color = 32;
	unsigned int	ft_isprint_color = 126;

	printf("\033[0m\033[1m___ft_isprint___\n\n");

	printf("\033[0m\033[38;5;%umisprint\n", isprint_color);
	printf("\033[0m\033[38;5;%umft_isprint\n\n", ft_isprint_color);

	for (int i = 0; i < 256; i++)
	{
		printf("\033[0m\033[38;5;%um∎ ", (isprint(i) == ft_isprint(i)) ? 46 : 160);
		printf("\033[0m[\033[38;5;%um. %c\033[0m] %d: \033[38;5;%um%d\033[0m\n",
		(isprint(i)) ? isprint_color : 7, i, i, ft_isprint(i) ? ft_isprint_color : 7, ft_isprint(i));
	}

	printf("\033[0m\033[1m\n______________\n\n");
}

void	test_ft_puts(void)
{
	char	*s = "Hello :D";

	printf("\033[0m\033[1m___ft_puts___\n\n");

	printf("ft_puts(%s):\n", s);
	ft_puts(s);

	printf("\033[0m\033[1m\n______________\n\n");
}

void	test_ft_toupper(void)
{
	unsigned int	toupper_color = 32;
	unsigned int	ft_toupper_color = 126;

	printf("\033[0m\033[1m___ft_toupper___\n\n");

	printf("\033[0m\033[38;5;%umtoupper\n", toupper_color);
	printf("\033[0m\033[38;5;%umft_toupper\n\n", ft_toupper_color);

	for (int i = 0; i < 128; i++)
	{
		printf("\033[0m\033[38;5;%um∎ ", (toupper(i) == ft_toupper(i)) ? 46 : 160);
		printf("\033[0m\033[38;5;%um%c\033[0m->\033[0m\033[38;5;%um%c\033[0m | \033[0m\033[38;5;%um%c\033[0m->\033[0m\033[38;5;%um%c\033[0m\n",
		toupper_color, i, toupper_color, toupper(i), ft_toupper_color, i, ft_toupper_color, ft_toupper(i));
	}

	printf("\033[0m\033[1m\n______________\n\n");
}

void	test_ft_tolower(void)
{
	unsigned int	tolower_color = 32;
	unsigned int	ft_tolower_color = 126;

	printf("\033[0m\033[1m___ft_tolower___\n\n");

	printf("\033[0m\033[38;5;%umtolower\n", tolower_color);
	printf("\033[0m\033[38;5;%umft_tolower\n\n", ft_tolower_color);

	for (int i = 0; i < 128; i++)
	{
		printf("\033[0m\033[38;5;%um∎ ", (tolower(i) == ft_tolower(i)) ? 46 : 160);
		printf("\033[0m\033[38;5;%um%c\033[0m->\033[0m\033[38;5;%um%c\033[0m | \033[0m\033[38;5;%um%c\033[0m->\033[0m\033[38;5;%um%c\033[0m\n",
		tolower_color, i, tolower_color, tolower(i), ft_tolower_color, i, ft_tolower_color, ft_tolower(i));
	}

	printf("\033[0m\033[1m\n______________\n\n");
}

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		test_ft_bzero();
		test_ft_strlen();
		test_ft_memcpy();
		test_ft_strcat();
		test_ft_memset();
		test_ft_strdup();
		test_ft_isalpha();
		test_ft_isdigit();
		test_ft_isalnum();
		test_ft_isascii();
		test_ft_isprint();
		test_ft_toupper();
		test_ft_tolower();
		test_ft_puts();
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
		else if (!strcmp(argv[i], "ft_memset"))
			test_ft_memset();
		else if (!strcmp(argv[i], "ft_strdup"))
			test_ft_strdup();
		else if (!strcmp(argv[i], "ft_isalpha"))
			test_ft_isalpha();
		else if (!strcmp(argv[i], "ft_isdigit"))
			test_ft_isdigit();
		else if (!strcmp(argv[i], "ft_isalnum"))
			test_ft_isalnum();
		else if (!strcmp(argv[i], "ft_isascii"))
			test_ft_isascii();
		else if (!strcmp(argv[i], "ft_isprint"))
			test_ft_isprint();
		else if (!strcmp(argv[i], "ft_toupper"))
			test_ft_toupper();
		else if (!strcmp(argv[i], "ft_tolower"))
			test_ft_tolower();
		else if (!strcmp(argv[i], "ft_puts"))
			test_ft_puts();
		else
			printf("unknown function %s\n", argv[i]);
	}
	return (0);
}