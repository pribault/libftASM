/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 16:07:55 by pribault          #+#    #+#             */
/*   Updated: 2018/02/10 21:29:27 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_asm.h"
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <ctype.h>

#define BUFFER_SIZE	4096
#define ARRAY_SIZE	127
#define STR			"Hello I'm a string :D"

int		out = -1;
int		null = -1;

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
	char	*s = STR;

	ft_puts(s);
}

void	test_puts_1(void)
{
	char	*s = STR;

	puts(s);
}

void	test_ft_strlen_1(void)
{
	ft_strlen(STR);
}

void	test_strlen_1(void)
{
	strlen(STR);
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
	{"strlen", &test_ft_strlen_1, &test_strlen_1},
	{"tolower", &test_ft_tolower_1, &test_tolower_1},
	{"toupper", &test_ft_toupper_1, &test_toupper_1},
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
		if ((now.tv_sec - start.tv_sec) * 1000000 + (now.tv_usec - start.tv_usec) >=
			seconds)
			finish = 1;
		count++;
	}
	return (count);
}

void	test_function(t_test *to_test, size_t seconds)
{
	char	buff[BUFFER_SIZE];
	size_t	count[2];

	null = open("/dev/null", O_WRONLY);

	printf("_____ft_%s_____\n\n", to_test->name);

	printf("testing ft_%s for %lu seconds:\n", to_test->name, seconds);
	dup2(null, 1);
	count[0] = test_loop(to_test->mine, seconds);
	dup2(out, 1);

	printf("testing %s for %lu seconds:\n", to_test->name, seconds);
	dup2(null, 1);
	count[1] = test_loop(to_test->real, seconds);
	dup2(out, 1);

	printf("\n_____%lu%%_____\n\n", (count[1] * 100) / count[0]);
}

int		main(int argc, char **argv)
{
	null = open("/dev/null", O_WRONLY);
	out = open("/dev/fd/1", O_WRONLY);

	for (size_t i = 0; g_test[i].name; i++)
	{
		test_function(&g_test[i], 1);
	}
	close(null);
	close(out);
	return (0);
}
