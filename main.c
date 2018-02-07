/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 16:20:27 by pribault          #+#    #+#             */
/*   Updated: 2018/02/07 13:09:10 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_asm.h"
#include <stdio.h>
#include <string.h>

void	test(long a)
{
	printf("receiving %ld\n", a);
}

void	memdump(void *ptr, size_t size)
{
	for (size_t i = 0; i < size; i++)
		printf("%.2hhx ", *(unsigned char*)(ptr + i));
	printf("\n");
}

int	main(int argc, char **argv)
{
	char		a[9];

	memset(&a, 1, sizeof(a));
	memdump(&a, sizeof(a));
	ft_bzero(&a, sizeof(a));
	memdump(&a, sizeof(a));
	return (0);
}