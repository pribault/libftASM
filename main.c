/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 16:07:55 by pribault          #+#    #+#             */
/*   Updated: 2018/02/12 13:03:17 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_asm.h"
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdlib.h>
#include <inttypes.h>

#define SPEED		1

#define BUFFER_SIZE	4096
#define ARRAY_SIZE	8192
#define STR_SAD		"Hello I'm a string ;("
#define STR1		"Hello I'm a string :D"
#define STR2		"Hello I'm "
#define STR3		"concatenated"

int		out = -1;
int		null = -1;

static void	ft_old_swap_2(void *a, void *b, size_t size, size_t i)
{
	if (i + 1 < size)
	{
		*(uint16_t*)(a + i) ^= *(uint16_t*)(b + i);
		*(uint16_t*)(b + i) ^= *(uint16_t*)(a + i);
		*(uint16_t*)(a + i) ^= *(uint16_t*)(b + i);
		i += 2;
	}
	if (i < size)
	{
		*(uint8_t*)(a + i) ^= *(uint8_t*)(b + i);
		*(uint8_t*)(b + i) ^= *(uint8_t*)(a + i);
		*(uint8_t*)(a + i) ^= *(uint8_t*)(b + i);
		i++;
	}
}

void		ft_old_swap(void *a, void *b, size_t size)
{
	size_t	i;

	if (!a || !b)
		return ;
	i = 0;
	while (i + 7 < size)
	{
		*(uint64_t*)(a + i) ^= *(uint64_t*)(b + i);
		*(uint64_t*)(b + i) ^= *(uint64_t*)(a + i);
		*(uint64_t*)(a + i) ^= *(uint64_t*)(b + i);
		i += 8;
	}
	if (i + 3 < size)
	{
		*(uint32_t*)(a + i) ^= *(uint32_t*)(b + i);
		*(uint32_t*)(b + i) ^= *(uint32_t*)(a + i);
		*(uint32_t*)(a + i) ^= *(uint32_t*)(b + i);
		i += 4;
	}
	ft_old_swap_2(a, b, size, i);
}

void	test_ft_bzero_1(void)
{
	static char	a[ARRAY_SIZE];

	ft_bzero(&a, ARRAY_SIZE);
}

void	test_bzero_1(void)
{
	static char	a[ARRAY_SIZE];

	bzero(&a, ARRAY_SIZE);
}

void	test_ft_memcpy_1(void)
{
	static char	a[ARRAY_SIZE];
	static char	b[ARRAY_SIZE];

	ft_memcpy(&a, &b, ARRAY_SIZE);
}

void	test_memcpy_1(void)
{
	static char	a[ARRAY_SIZE];
	static char	b[ARRAY_SIZE];

	memcpy(&a, &b, ARRAY_SIZE);
}

void	test_ft_memset_1(void)
{
	static char	a[ARRAY_SIZE];

	ft_memset(&a, 42, ARRAY_SIZE);
}

void	test_memset_1(void)
{
	static char	a[ARRAY_SIZE];

	ft_memset(&a, 42, ARRAY_SIZE);
}

void	test_ft_puts_1(void)
{
	char	*s = STR1;

	ft_puts(s);
}

void	test_puts_1(void)
{
	char	*s = STR1;

	puts(s);
}

void	test_ft_strcat_1(void)
{
	char	s[ARRAY_SIZE] = STR2;

	ft_strcat(s, STR3);
}

void	test_strcat_1(void)
{
	char	s[ARRAY_SIZE] = STR2;

	strcat(s, STR3);
}

void	test_ft_strdup_1(void)
{
	free(ft_strdup(STR1));
}

void	test_strdup_1(void)
{
	free(strdup(STR1));
}

void	test_ft_strlen_1(void)
{
	ft_strlen(STR1);
}

void	test_strlen_1(void)
{
	strlen(STR1);
}

void	test_ft_tolower_1(void)
{
	int	ret = ft_tolower('A');
}

void	test_tolower_1(void)
{
	int	ret = tolower('A');
}

void	test_ft_toupper_1(void)
{
	int	ret = ft_toupper('A');
}

void	test_toupper_1(void)
{
	int ret = toupper('A');
}

void	test_ft_isalnum_1(void)
{
	int	ret = ft_isalnum('A');
}

void	test_isalnum_1(void)
{
	int	ret = isalnum('A');
}

void	test_ft_isalpha_1(void)
{
	int	ret = ft_isalpha('A');
}

void	test_isalpha_1(void)
{
	int	ret = isalpha('A');
}

void	test_ft_isascii_1(void)
{
	int	ret = ft_isascii('A');
}

void	test_isascii_1(void)
{
	int	ret = isascii('A');
}

void	test_ft_isdigit_1(void)
{
	int	ret = ft_isdigit('A');
}

void	test_isdigit_1(void)
{
	int	ret = isdigit('A');
}

void	test_ft_isprint_1(void)
{
	int	ret = ft_isprint('A');
}

void	test_isprint_1(void)
{
	int	ret = isprint('A');
}

void	test_ft_cat_1(void)
{
	system("./ft_cat Makefile");
}

void	test_cat_1(void)
{
	system("cat Makefile");
}

void	test_ft_memcmp_1(void)
{
	char	a[ARRAY_SIZE];
	char	b[ARRAY_SIZE];

	bzero(&a, ARRAY_SIZE);
	bzero(&b, ARRAY_SIZE);
	b[ARRAY_SIZE - 1] = 1;
	ft_memcmp(&a, &b, ARRAY_SIZE);
}

void	test_memcmp_1(void)
{
	char	a[ARRAY_SIZE];
	char	b[ARRAY_SIZE];

	bzero(&a, ARRAY_SIZE);
	bzero(&b, ARRAY_SIZE);
	b[ARRAY_SIZE - 1] = 1;
	memcmp(&a, &b, ARRAY_SIZE);
}

void	test_ft_strcmp_1(void)
{
	ft_strcmp(STR1, STR_SAD);
}

void	test_strcmp_1(void)
{
	strcmp(STR1, STR_SAD);
}

void	test_ft_swap_1(void)
{
	char	a[ARRAY_SIZE];
	char	b[ARRAY_SIZE];

	ft_swap(&a, &b, ARRAY_SIZE);
}

void	test_old_swap_1(void)
{
	char	a[ARRAY_SIZE];
	char	b[ARRAY_SIZE];

	ft_old_swap(&a, &b, ARRAY_SIZE);
}

typedef void	(*t_func)(void);

typedef struct	s_test
{
	char		*name;
	t_func		mine;
	t_func		real;
}				t_test;

static t_test	g_test[] =
{
	{"bzero", &test_ft_bzero_1, &test_bzero_1},
	{"memcpy", &test_ft_memcpy_1, &test_memcpy_1},
	{"memset", &test_ft_memset_1, &test_memset_1},
	{"puts", &test_ft_puts_1, &test_puts_1},
	{"strcat", &test_ft_strcat_1, &test_strcat_1},
	{"strdup", &test_ft_strdup_1, &test_ft_strdup_1},
	{"strlen", &test_ft_strlen_1, &test_strlen_1},
	{"tolower", &test_ft_tolower_1, &test_tolower_1},
	{"toupper", &test_ft_toupper_1, &test_toupper_1},
	{"isalnum", &test_ft_isalnum_1, &test_isalnum_1},
	{"isalpha", &test_ft_isalpha_1, &test_isalpha_1},
	{"isascii", &test_ft_isascii_1, &test_isascii_1},
	{"isdigit", &test_ft_isdigit_1, &test_isdigit_1},
	{"isprint", &test_ft_isprint_1, &test_isprint_1},
	{"cat", &test_ft_cat_1, &test_cat_1},
	{"memcmp", &test_ft_memcmp_1, &test_memcmp_1},
	{"strcmp", &test_ft_strcmp_1, &test_strcmp_1},
	{"swap", &test_ft_swap_1, &test_old_swap_1},
	{NULL, NULL}
};

size_t	test_loop(t_func func, size_t seconds)
{
	struct timeval	start;
	struct timeval	now;
	int				finish;
	size_t			count;

	finish = 0;
	count = 0;
	gettimeofday(&start, NULL);
	seconds *= 1000000;
	while (!finish)
	{
		func();
		gettimeofday(&now, NULL);
		if ((now.tv_sec - start.tv_sec) * 1000000 +
			(now.tv_usec - start.tv_usec) >= seconds)
			finish = 1;
		count++;
	}
	return (count);
}

void	test_function(t_test *to_test, size_t seconds)
{
	static size_t	max = 200;
	static uint8_t	colors[] = {196, 202, 208, 214, 226, 154, 118, 82, 46};
	static uint8_t	title = 39;
	char	buff[BUFFER_SIZE];
	size_t	count[3];

	null = open("/dev/null", O_WRONLY);

	printf("_____\033[38;5;%hhumft_%s\033[0m_____\n\n",
	title, to_test->name);

	printf("testing ft_%s for %lu seconds:\n", to_test->name, seconds);
	dup2(null, 1);
	count[0] = test_loop(to_test->mine, seconds);
	dup2(out, 1);
	printf("\t%lu iterations\n", count[0]);

	printf("testing %s for %lu seconds:\n", to_test->name, seconds);
	dup2(null, 1);
	count[1] = test_loop(to_test->real, seconds);
	dup2(out, 1);
	printf("\t%lu iterations\n", count[1]);

	count[2] = (count[0] * 100) / count[1];
	if (count[2] <= max)
		printf("\n_____\033[38;5;%hhum%lu%%\033[0m_____\n\n",
		colors[(count[2] * (sizeof(colors) - 1)) / max], count[2]);
	else
		printf("\n_____\033[1m\033[4m\033[38;5;10m%lu%%\033[0m_____\n\n",
		count[2]);
}

int		main(int argc, char **argv)
{
	null = open("/dev/null", O_WRONLY);
	out = open("/dev/fd/1", O_WRONLY);

	for (size_t i = 0; g_test[i].name; i++)
	{
		test_function(&g_test[i], SPEED);
	}
	close(null);
	close(out);
	return (0);
}
