/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 20:44:07 by pribault          #+#    #+#             */
/*   Updated: 2018/02/17 13:02:00 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft_asm.h"

int		main(int argc, char **argv)
{
	int	fd;

	if (argc == 1)
		ft_cat(0);
	else if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) != -1)
			ft_cat(fd);
	}
	else
		return (1);
	return (0);
}
