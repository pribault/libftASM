/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 16:07:55 by pribault          #+#    #+#             */
/*   Updated: 2018/02/15 13:07:40 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void	benchmark(char **args, int n);
void	test(char **args, int n);

int		null = -1;
int		out = -1;

int		main(int argc, char **argv)
{
	null = open("/dev/null", O_WRONLY);
	out = open("/dev/fd/1", O_WRONLY);
	setvbuf(stdout, NULL, _IONBF, 0);
	test(&argv[1], argc - 1);
	benchmark(&argv[1], argc - 1);
	close(null);
	close(out);
	return (0);
}
