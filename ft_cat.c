/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 20:44:07 by pribault          #+#    #+#             */
/*   Updated: 2018/02/10 15:55:15 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft_asm.h"

int		main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (1);
	if ((fd = open(argv[1], O_RDONLY)) != -1)
		ft_cat(fd);
	return (0);
}
