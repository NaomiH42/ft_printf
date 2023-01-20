/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:42:25 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/20 15:15:40 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int	is_in(char c, char *flags)
{
	size_t	i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == c)
			return (1);
		i++;
	}
	return (0);
}

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
                if ((flags[0] >= '0' && flags[0] <= '9') || flags[0] == ' ')
                {
                        while ((flags[i] >= '0' && flags[i] <= '9') || flags[i] == ' ')
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

size_t	put_zero(size_t n)
{
	size_t	i;
	char	zero;

	zero = '0';
	i = 0;
	while (i < n)
	{
		write(1, &zero, 1);
		i++;
	}
	return (i);
}
