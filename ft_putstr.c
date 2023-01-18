/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:51:29 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/19 00:20:15 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putstr(char *s, char *flags, int test)
{
	size_t	i;
	int	spaces;
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
	spaces = spaces - ft_strlen(s);
	i = 0;
	if (flags[i] == '-' && test)
	{
		while (*s)
		{
			write(1, &(*s), 1);
			s++;
		}
		flag = 1;
	}
	while (spaces > 0 && test)
	{
		write(1, &space, 1);
		spaces--;
	}
	if (flag == 0 || test)
	{
		while (*s)
		{
			write(1, &(*s), 1);
			s++;
		}
	}
}
