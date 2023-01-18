/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:51:14 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/19 00:19:18 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putchar(char c, char *flags, int test)
{
	size_t	i;
	size_t	spaces;
	int	flag;
	char	space;

	flag = 0;
	spaces = 0;
	i = 0;
	space = ' ';
	while (flags[i] && test)
	{
		if (flags[i] >= '0' && flags[i] <= '9')
			spaces = (spaces * 10) + flags[i] - '0';
		i++;
	}
	i = 0;
	if (flags[i] == '-' && test)
	{
		write(1, &c, 1);
		flag = 1;
	}
	while (spaces > 0 && test)
	{
		write(1, &space, 1);
		spaces--;
	}
	if (flag == 0 || !test)
		write(1, &c, 1);
}

