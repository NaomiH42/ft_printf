/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putmem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:01:56 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/19 17:16:47 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stddef.h>

static void	hex(unsigned long long nbr, char *flags)
{
	unsigned long long	length;
	char	*base;

	base = "0123456789abcdef";
	length = 16;
	
	if (nbr >= length)
	{
		hex(nbr / length, flags);
		hex(nbr % length, flags);
	}
	if (nbr < length)
		ft_putchar(base[nbr], flags, 0);
}

static void	show_adr(void *ptr, char *flags)
{	
	unsigned long long	adr;

	adr = (unsigned long long)&ptr;
	if (!ptr)
		ft_putstr("(nil)", flags, 0);
	else
	{
		ft_putchar('0', flags, 0);
		ft_putchar('x', flags, 0);
		hex(adr, flags);
	}
}
#include <stdio.h>

size_t	putmem(void *ptr, char *flags)
{
	int	flag;
	int	spaces;
	int	i;
	char	space;
	size_t	ret;

	ret = 0;
	flag = 0;
	spaces = 0;
	i = 0;
	space = ' ';
	while (flags[i])
	{
                if (flags[i] >= '0' && flags[i] <= '9')
                        spaces = (spaces * 10) + flags[i] - '0';
                i++;
        }
	if (!ptr)
		spaces -= 5;
	else
		spaces -= 14;
	if (spaces > 0)
		ret = spaces;
	else
	{
		if (!ptr)
			ret = 5;
		else
			ret = 14;
	}
	if (flags[0] == '-')
	{
		show_adr(ptr, flags);
		flag = 1;
	}
	while (spaces > 0)
	{
		write(1, &space, 1);
		spaces--;
	}
	if (flag == 0)
		show_adr(ptr, flags);
	return (ret);
}
