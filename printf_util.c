/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:42:25 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/19 19:56:48 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

size_t	dot(char *flags)
{
	size_t	i;
	int	res;

	res = 0;
	i = 0;
	if (!flags)
		return (0);
	while (flags[i])
	{
		if (flags[i] == '.')
		{
			while ((flags[i] >= '0' && flags[i] <= '9') || flags[i] == '.')
			{
				if (flags[i] != '.')
					res = (res * 10) + flags[i] - '0';
				i++;
			}
		}
		else
			i++;
	}
	return (res);
}

size_t  minus(char *flags)
{
        size_t  i;
        int     res;

        res = 0;
        i = 0;
        if (!flags)
                return (0);
        while (flags[i])
        {
                if (flags[i] == '-')
                {
                        i++;
                        while (flags[i] >= '0' && flags[i] <= '9')
                        {
                                res = (res * 10) + flags[i] - '0';
                                i++;
                        }
                }
		i++;
        }
	return (res);
}

size_t  space(char *flags)
{       
        size_t  i;
        int     res;

        res = 0;
        i = 0;
        if (!flags)
                return (0);
        while (flags[i])
        {
                if (flags[0] >= '0' && flags[0] <= '9')
                {
                        while (flags[i] >= '0' && flags[i] <= '9')
                        {
                                res = (res * 10) + flags[i] - '0';
                                i++;
                        }
			break;
                }
		i++;
        }
	return (res);
}

size_t	put_space(size_t n)
{
	size_t	i;
	char	space;

	space = ' ';
	i = 0;
	while (i < n)
	{
		write(1, &space, 1);
		i++;
	}
	return (i);
}
