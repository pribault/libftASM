/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_asm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 16:16:34 by pribault          #+#    #+#             */
/*   Updated: 2018/02/14 13:19:23 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_ASM_H
# define LIBFT_ASM_H

/*
****************
**	includes  **
****************
*/

# include <strings.h>

/*
***************
**	defines  **
***************
*/

# define BYTE(x)	(1 << x)

# define ISASCII	BYTE(0)
# define ISALNUM	BYTE(3)
# define ISALPHA	BYTE(10)
# define ISDIGIT	BYTE(11)
# define ISPRINT	BYTE(14)

/*
******************
**	prototypes  **
******************
*/

void	ft_bzero(void *s, size_t n);
char	*ft_strcat(char *dest, const char *src);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strcat(char *dest, const char *src);

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isblank(int c);
int		ft_whatis(int c);

int		ft_puts(char *s);
int		ft_toupper(int c);
int		ft_tolower(int c);

int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_swap(void *a, void *b, size_t n);

void	ft_cat(int fd);

void	ft_memdump(void *ptr, size_t size);

#endif
