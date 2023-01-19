/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 00:56:02 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/19 18:22:07 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	perc(void)
{
	char	p;

	p = '%';
/*	int	spaces;
	int	flag;
	char	space;
	size_t	ret;
	char	p;
	size_t	i;

	i = 0;
	p = '%';
	ret = 1;
	flag = 0;
	spaces = 0;
	space = ' ';
	while (flags[i])
	{
		if (flags[i] >= '0' && flags[i] <= '9')
			spaces = (spaces * 10) + flags[i] - '0';
		i++;
	}
	spaces -= 1;
	if (flags[i] == '-')
	{
		write(1, &p, 1);
		flag = 1;
	}
	while (spaces > 0)
	{
		write(1, &space, 1);
		spaces--;
		ret++;
	}
	if (flag == 0)
		write(1, &p, 1);
*/
	write(1, &p, 1);
	return (1);
}
