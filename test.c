/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 11:13:17 by pribault          #+#    #+#             */
/*   Updated: 2018/02/15 13:23:08 by pribault         ###   ########.fr       */
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

static int	test_ft_memcmp_1(void)
{
	char	a[ARRAY_SIZE];
	char	b[ARRAY_SIZE];
	int		reta;
	int		retb;

	memset(&a, 42, ARRAY_SIZE);
	memset(&b, 42, ARRAY_SIZE);
	reta = ft_memcmp(&a, &b, ARRAY_SIZE);
	retb = memcmp(&a, &b, ARRAY_SIZE);
	dprintf(1, "ft_memcmp: %d\nmemcmp: %d\n", reta, retb);
	return ((reta != retb) ? 1 : 0);
}

static int	test_ft_memcmp_rand(void)
{
	struct timeval	time;
	char	a[ARRAY_SIZE];
	char	b[ARRAY_SIZE];
	int		reta;
	int		retb;

	gettimeofday(&time, NULL);
	srand(time.tv_sec * time.tv_usec);
	for (size_t i = 0; i < ARRAY_SIZE; i++)
	{
		a[i] = rand();
		b[i] = rand();
	}
	reta = ft_memcmp(&a, &b, ARRAY_SIZE);
	retb = memcmp(&a, &b, ARRAY_SIZE);
	dprintf(1, "ft_memcmp: %d\nmemcmp: %d\n", reta, retb);
	return ((reta != retb) ? 1 : 0);
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
			dprintf(1, (isprint(i)) ? "[%c]: ft_tolower=%d tolower=%d\n" :
			"[%d]: ft_tolower=%d tolower=%d\n",
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
			dprintf(1, (isprint(i)) ? "[%c]: ft_toupper=%d toupper=%d\n" :
			"[%d]: ft_toupper=%d toupper=%d\n",
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
			dprintf(1, (isprint(i)) ? "[%c]: ft_isalnum=%d isalnum=%d\n" :
			"[%d]: ft_isalnum=%d isalnum=%d\n",
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
			dprintf(1, (isprint(i)) ? "[%c]: ft_isalpha=%d isalpha=%d\n" :
			"[%d]: ft_isalpha=%d isalpha=%d\n",
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
			dprintf(1, (isprint(i)) ? "[%c]: ft_isascii=%d isascii=%d\n" :
			"[%d]: ft_isascii=%d isascii=%d\n",
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
			dprintf(1, (isprint(i)) ? "[%c]: ft_isdigit=%d isdigit=%d\n" :
			"[%d]: ft_isdigit=%d isdigit=%d\n",
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
			dprintf(1, (isprint(i)) ? "[%c]: ft_isprint=%d isprint=%d\n" :
			"[%d]: ft_isprint=%d isprint=%d\n",
			i, ft_isprint(i), isprint(i));
			ret = 1;
		}
	}
	return (ret);
}

static int	test_ft_isblank(void)
{
	int	ret;

	ret = 0;
	for (int i = MIN; i <= MAX; i++)
	{
		if (ft_isblank(i) != isblank(i))
		{
			dprintf(1, (isprint(i)) ? "[%c]: ft_isblank=%d isblank=%d\n" :
			"[%d]: ft_isblank=%d isblank=%d\n",
			i, ft_isblank(i), isblank(i));
			ret = 1;
		}
	}
	return (ret);
}

static int	test_ft_iscntrl(void)
{
	int	ret;

	ret = 0;
	for (int i = MIN; i <= MAX; i++)
	{
		if (ft_iscntrl(i) != iscntrl(i))
		{
			dprintf(1, (isprint(i)) ? "[%c]: ft_iscntrl=%d iscntrl=%d\n" :
			"[%d]: ft_iscntrl=%d iscntrl=%d\n",
			i, ft_iscntrl(i), iscntrl(i));
			ret = 1;
		}
	}
	return (ret);
}

static int	test_ft_isgraph(void)
{
	int	ret;

	ret = 0;
	for (int i = MIN; i <= MAX; i++)
	{
		if (ft_isgraph(i) != isgraph(i))
		{
			dprintf(1, (isprint(i)) ? "[%c]: ft_isgraph=%d isgraph=%d\n" :
			"[%d]: ft_isgraph=%d isgraph=%d\n",
			i, ft_isgraph(i), isgraph(i));
			ret = 1;
		}
	}
	return (ret);
}

static int	test_ft_islower(void)
{
	int	ret;

	ret = 0;
	for (int i = MIN; i <= MAX; i++)
	{
		if (ft_islower(i) != islower(i))
		{
			dprintf(1, (isprint(i)) ? "[%c]: ft_islower=%d islower=%d\n" :
			"[%d]: ft_islower=%d islower=%d\n",
			i, ft_islower(i), islower(i));
			ret = 1;
		}
	}
	return (ret);
}

static int	test_ft_isupper(void)
{
	int	ret;

	ret = 0;
	for (int i = MIN; i <= MAX; i++)
	{
		if (ft_isupper(i) != isupper(i))
		{
			dprintf(1, (isprint(i)) ? "[%c]: ft_isupper=%d isupper=%d\n" :
			"[%d]: ft_isupper=%d isupper=%d\n",
			i, ft_isupper(i), isupper(i));
			ret = 1;
		}
	}
	return (ret);
}

static int	test_ft_isspace(void)
{
	int	ret;

	ret = 0;
	for (int i = MIN; i <= MAX; i++)
	{
		if (ft_isspace(i) != isspace(i))
		{
			dprintf(1, (isprint(i)) ? "[%c]: ft_isspace=%d isspace=%d\n" :
			"[%d]: ft_isspace=%d isspace=%d\n",
			i, ft_isspace(i), isspace(i));
			ret = 1;
		}
	}
	return (ret);
}

static int	test_ft_isxdigit(void)
{
	int	ret;

	ret = 0;
	for (int i = MIN; i <= MAX; i++)
	{
		if (ft_isxdigit(i) != isxdigit(i))
		{
			dprintf(1, (isprint(i)) ? "[%c]: ft_isxdigit=%d isxdigit=%d\n" :
			"[%d]: ft_isxdigit=%d isxdigit=%d\n",
			i, ft_isxdigit(i), isxdigit(i));
			ret = 1;
		}
	}
	return (ret);
}

# define ISASCII	BYTE(0)
# define ISCNTRL	BYTE(1)
# define ISALNUM	BYTE(3)
# define ISUPPER	BYTE(8)
# define ISLOWER	BYTE(9)
# define ISALPHA	BYTE(10)
# define ISDIGIT	BYTE(11)
# define ISXDIGIT	BYTE(12)
# define ISSPACE	BYTE(13)
# define ISPRINT	BYTE(14)
# define ISGRAPH	BYTE(15)

static int	test_ft_whatis(void)
{
	int	ret;

	for (int i = MIN; i <= MAX; i++)
	{
		ret = ft_whatis(i);
		dprintf(1, (isprint(i)) ? "[%c] is:\n" : "[%d] is:\n", i);
		if (ret & ISASCII)
			dprintf(1, " - ascii\n");
		if (ret & ISCNTRL)
			dprintf(1, " - control\n");
		if (ret & ISALNUM)
			dprintf(1, " - alnum\n");
		if (ret & ISUPPER)
			dprintf(1, " - upper\n");
		if (ret & ISLOWER)
			dprintf(1, " - lower\n");
		if (ret & ISALPHA)
			dprintf(1, " - alpha\n");
		if (ret & ISDIGIT)
			dprintf(1, " - digit\n");
		if (ret & ISXDIGIT)
			dprintf(1, " - xdigit\n");
		if (ret & ISSPACE)
			dprintf(1, " - space\n");
		if (ret & ISPRINT)
			dprintf(1, " - printable\n");
		if (ret & ISGRAPH)
			dprintf(1, " - graph\n");
	}
	return (2);
}

typedef int		(*t_func)(void);

typedef struct	s_test
{
	char		*name;
	t_func		func;
	char		print;
}				t_test;

static t_test	g_test[] =
{
	{"bzero", &test_ft_bzero_1, 1},
	{"memcmp", &test_ft_memcmp_1, 1},
	{"memcmp", &test_ft_memcmp_rand, 1},
	{"memcpy", &test_ft_memcpy_1, 1},
	{"memset", &test_ft_memset_1, 1},
	{"memset", &test_ft_memset_2, 1},
	{"puts", &test_ft_puts_1, 1},
	{"strcat", &test_ft_strcat_1, 1},
	{"strdup", &test_ft_strdup_1, 1},
	{"strlen", &test_ft_strlen_1, 1},
	{"strlen", &test_ft_strlen_2, 1},
	{"tolower", &test_ft_tolower, 1},
	{"toupper", &test_ft_toupper, 1},
	{"isalnum", &test_ft_isalnum, 1},
	{"isalpha", &test_ft_isalpha, 1},
	{"isascii", &test_ft_isascii, 1},
	{"isdigit", &test_ft_isdigit, 1},
	{"isprint", &test_ft_isprint, 1},
	{"isblank", &test_ft_isblank, 1},
	{"iscntrl", &test_ft_iscntrl, 1},
	{"isgraph", &test_ft_isgraph, 1},
	{"islower", &test_ft_islower, 1},
	{"isupper", &test_ft_isupper, 1},
	{"isspace", &test_ft_isspace, 1},
	{"isxdigit", &test_ft_isxdigit, 1},
	{"whatis", &test_ft_whatis, 0},
	{NULL, NULL}
};

void		test(char **args, int n)
{
	static char	buffer[BUFFER_SIZE];
	size_t		i, j;
	int			fd[2];
	int			ret;
	int			found;

	if (n)
	{
		for (j = 0; j < n; j++)
		{
			found = 0;
			for (i = 0; g_test[i].name; i++)
			{
				if (!strcmp(args[j], g_test[i].name) ||
					(!strncmp(args[j], "ft_", 3) &&
					!strcmp(&args[j][3], g_test[i].name)))
				{
					found = 1;
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
			}
			if (!found)
				dprintf(out, "no test for %s\n", args[j]);
		}
	}
	else
	{
		for (i = 0; g_test[i].name; i++)
		{
			if (g_test[i].print)
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
		}
	}
	dprintf(out, "\n\n");
}