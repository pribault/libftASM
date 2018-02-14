/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 11:13:17 by pribault          #+#    #+#             */
/*   Updated: 2018/02/14 13:13:22 by pribault         ###   ########.fr       */
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
#include <string.h>

#define SPEED		1

#define BUFFER_SIZE	4096
#define ARRAY_SIZE	127
#define STR_SAD		"Hello I'm a string ;("
#define STR1		"Hello I'm a string :D"
#define STR2		"Hello I'm "
#define STR3		"concatenated"

#define MIN			0
#define MAX			255

extern int	out;
extern int	null;

static void	memdump(void *ptr, size_t size)
{
	for (size_t i = 0; i < size; i++)
		dprintf(1, "%.2hhx ", *(uint8_t*)(ptr + i));
	dprintf(1, "\n");
}

static int	test_ft_bzero_1(void)
{
	char	a[ARRAY_SIZE];
	char	b[ARRAY_SIZE];

	memset(&a, 42, ARRAY_SIZE);
	memset(&b, 42, ARRAY_SIZE);
	ft_bzero(&a, ARRAY_SIZE);
	bzero(&b, ARRAY_SIZE);
	dprintf(1, "ft_bzero:\n");
	memdump(&a, ARRAY_SIZE);
	dprintf(1, "bzero:\n");
	memdump(&b, ARRAY_SIZE);
	return ((memcmp(&a, &b, ARRAY_SIZE)) ? 1 : 0);
}

static int	test_ft_memcpy_1(void)
{
	char	a1[ARRAY_SIZE];
	char	a2[ARRAY_SIZE];
	char	b1[ARRAY_SIZE];
	char	b2[ARRAY_SIZE];

	memset(&a1, 42, ARRAY_SIZE);
	a1[ARRAY_SIZE / 2] = 8;
	memset(&a2, 42, ARRAY_SIZE);
	a2[ARRAY_SIZE / 2] = 8;
	bzero(&b1, ARRAY_SIZE);
	bzero(&b2, ARRAY_SIZE);
	ft_memcpy(&b1, &a1, ARRAY_SIZE);
	memcpy(&b2, &a2, ARRAY_SIZE);
	dprintf(1, "ft_memcpy:\n");
	memdump(&b1, ARRAY_SIZE);
	dprintf(1, "memcpy:\n");
	memdump(&b2, ARRAY_SIZE);
	return ((memcmp(&b1, &b2, ARRAY_SIZE)) ? 1 : 0);
}

static int	test_ft_memset_1(void)
{
	char	a[ARRAY_SIZE];
	char	b[ARRAY_SIZE];

	bzero(&a, ARRAY_SIZE);
	bzero(&b, ARRAY_SIZE);
	ft_memset(&a, 42, ARRAY_SIZE);
	memset(&b, 42, ARRAY_SIZE);
	dprintf(1, "ft_memset:\n");
	memdump(&a, ARRAY_SIZE);
	dprintf(1, "memset:\n");
	memdump(&b, ARRAY_SIZE);
	return ((memcmp(&a, &b, ARRAY_SIZE)) ? 1 : 0);
}

static int	test_ft_memset_2(void)
{
	char	a[ARRAY_SIZE];
	char	b[ARRAY_SIZE];

	bzero(&a, ARRAY_SIZE);
	bzero(&b, ARRAY_SIZE);
	ft_memset(&a, 0x4200, ARRAY_SIZE);
	memset(&b, 0x4200, ARRAY_SIZE);
	dprintf(1, "ft_memset:\n");
	memdump(&a, ARRAY_SIZE);
	dprintf(1, "memset:\n");
	memdump(&b, ARRAY_SIZE);
	return ((memcmp(&a, &b, ARRAY_SIZE)) ? 1 : 0);
}

static int	test_ft_puts_1(void)
{
	dprintf(1, "ft_puts:\n");
	ft_puts(STR1);
	dprintf(1, "puts:\n");
	puts(STR1);
	return (2);
}

static int	test_ft_strcat_1(void)
{
	char	a[ARRAY_SIZE] = STR2;
	char	b[ARRAY_SIZE] = STR2;
	char	*reta;
	char	*retb;

	dprintf(1, "concatenating \"%s\" and \"%s\"\n\n", STR2, STR3);
	reta = ft_strcat((char*)&a, STR3);
	dprintf(1, "ft_strcat:\n%s\nret=%p\n", (char*)&a, reta);
	retb = strcat((char*)&b, STR3);
	dprintf(1, "strcat:\n%s\nret=%p\n", (char*)&b, retb);

	return ((reta != (char*)&a || retb != (char*)&b ||
		strcmp((char*)&a, (char*)&b)) ? 1 : 0);
}

static int	test_ft_strdup_1(void)
{
	char	*a;
	char	*b;

	a = ft_strdup(STR1);
	dprintf(1, "ft_strdup:\n%s\n", a);
	b = strdup(STR1);
	dprintf(1, "strdup:\n%s\n", b);
	free(a);
	free(b);
	return ((strcmp(a, b)) ? 1 : 0);
}

static int	test_ft_strlen_1(void)
{
	size_t	a;
	size_t	b;

	a = ft_strlen(STR1);
	dprintf(1, "ft_strlen(%s)=%lu\n", STR1, a);
	b = strlen(STR1);
	dprintf(1, "strlen(%s)=%lu\n", STR1, b);
	return ((a != b) ? 1 : 0);
}

static int	test_ft_strlen_2(void)
{
	size_t	a;
	size_t	b;

	a = ft_strlen("");
	dprintf(1, "ft_strlen(%s)=%lu\n", "", a);
	b = strlen("");
	dprintf(1, "strlen(%s)=%lu\n", "", b);
	return ((a != b) ? 1 : 0);
}

static int	test_ft_tolower(void)
{
	int	ret;

	ret = 0;
	for (int i = MIN; i <= MAX; i++)
	{
		if (ft_tolower(i) != tolower(i))
		{
			dprintf(1, "[%d]: ft_tolower=%d tolower=%d\n",
			i, ft_tolower(i), tolower(i));
			ret = 1;
		}
	}
	return (ret);
}

static int	test_ft_toupper(void)
{
	int	ret;

	ret = 0;
	for (int i = MIN; i <= MAX; i++)
	{
		if (ft_toupper(i) != toupper(i))
		{
			dprintf(1, "[%d]: ft_toupper=%d toupper=%d\n",
			i, ft_toupper(i), toupper(i));
			ret = 1;
		}
	}
	return (ret);
}

static int	test_ft_isalnum(void)
{
	int	ret;

	ret = 0;
	for (int i = MIN; i <= MAX; i++)
	{
		if (ft_isalnum(i) != isalnum(i))
		{
			dprintf(1, "[%d]: ft_isalnum=%d isalnum=%d\n",
			i, ft_isalnum(i), isalnum(i));
			ret = 1;
		}
	}
	return (ret);
}

static int	test_ft_isalpha(void)
{
	int	ret;

	ret = 0;
	for (int i = MIN; i <= MAX; i++)
	{
		if (ft_isalpha(i) != isalpha(i))
		{
			dprintf(1, "[%d]: ft_isalpha=%d isalpha=%d\n",
			i, ft_isalpha(i), isalpha(i));
			ret = 1;
		}
	}
	return (ret);
}

static int	test_ft_isascii(void)
{
	int	ret;

	ret = 0;
	for (int i = MIN; i <= MAX; i++)
	{
		if (ft_isascii(i) != isascii(i))
		{
			dprintf(1, "[%d]: ft_isascii=%d isascii=%d\n",
			i, ft_isascii(i), isascii(i));
			ret = 1;
		}
	}
	return (ret);
}

static int	test_ft_isdigit(void)
{
	int	ret;

	ret = 0;
	for (int i = MIN; i <= MAX; i++)
	{
		if (ft_isdigit(i) != isdigit(i))
		{
			dprintf(1, "[%d]: ft_isdigit=%d isdigit=%d\n",
			i, ft_isdigit(i), isdigit(i));
			ret = 1;
		}
	}
	return (ret);
}

static int	test_ft_isprint(void)
{
	int	ret;

	ret = 0;
	for (int i = MIN; i <= MAX; i++)
	{
		if (ft_isprint(i) != isprint(i))
		{
			dprintf(1, "[%d]: ft_isprint=%d isprint=%d\n",
			i, ft_isprint(i), isprint(i));
			ret = 1;
		}
	}
	return (ret);
}

static int	test_ft_whatis(void)
{
	int	ret;

	for (int i = MIN; i <= MAX; i++)
	{
		ret = ft_whatis(i);
		dprintf(1, (isprint(i)) ? "[%c] is:\n" : "[%d] is:\n", i);
		if (ret & ISASCII)
			dprintf(1, " - ascii\n");
		if (ret & ISALPHA)
			dprintf(1, " - alpha\n");
		if (ret & ISDIGIT)
			dprintf(1, " - digit\n");
		if (ret & ISALNUM)
			dprintf(1, " - alnum\n");
		if (ret & ISPRINT)
			dprintf(1, " - printable\n");
	}
	return (2);
}

typedef int		(*t_func)(void);

typedef struct	s_test
{
	char		*name;
	t_func		func;
}				t_test;

static t_test	g_test[] =
{
	{"bzero", &test_ft_bzero_1},
	{"memcpy", &test_ft_memcpy_1},
	{"memset 1", &test_ft_memset_1},
	{"memset 2", &test_ft_memset_2},
	{"puts", &test_ft_puts_1},
	{"strcat", &test_ft_strcat_1},
	{"strdup", &test_ft_strdup_1},
	{"strlen 1", &test_ft_strlen_1},
	{"strlen 2", &test_ft_strlen_2},
	{"tolower", &test_ft_tolower},
	{"toupper", &test_ft_toupper},
	{"isalnum", &test_ft_isalnum},
	{"isalpha", &test_ft_isalpha},
	{"isascii", &test_ft_isascii},
	{"isdigit", &test_ft_isdigit},
	{"isprint", &test_ft_isprint},
	// {"whatis", &test_ft_whatis},
	{NULL, NULL}
};

void		test(void)
{
	static char	buffer[BUFFER_SIZE];
	int			fd[2];
	int			ret;

	for (size_t i = 0; g_test[i].name; i++)
	{
		pipe(fd);
		dup2(fd[1], 1);

		if ((ret = g_test[i].func()) == 1)
		{
			close(fd[1]);
			dup2(out, 1);
			dprintf(out, "_____\033[38;5;196merror on ft_%s\033[0m_____\n\n",
			g_test[i].name);
			while ((ret = read(fd[0], &buffer, BUFFER_SIZE)) > 0)
				write(out, &buffer, ret);
			dprintf(out, "\n");
		}
		else if (ret == 2)
		{
			close(fd[1]);
			dup2(out, 1);
			dprintf(out, "_____\033[38;5;226mft_%s debug\033[0m_____\n\n",
			g_test[i].name);
			while ((ret = read(fd[0], &buffer, BUFFER_SIZE)) > 0)
				write(out, &buffer, ret);
			dprintf(out, "\n");
		}
		else
		{
			close(fd[1]);
			dup2(out, 1);
			dprintf(out, "_____\033[38;5;46mft_%s OK\033[0m_____\n\n",
			g_test[i].name);
			while ((ret = read(fd[0], &buffer, BUFFER_SIZE)) > 0)
				write(null, &buffer, ret);
		}

		close(fd[0]);
	}
	dprintf(out, "\n\n");
}
