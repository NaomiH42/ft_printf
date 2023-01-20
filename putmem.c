/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putmem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:01:56 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/20 21:26:57 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>

void	memprint(uintptr_t nbr, char *flags)
{
	if (nbr >= 16)
	{
		memprint(nbr / 16, flags);
		memprint(nbr % 16, flags);
	}
	else if (nbr <= 9)
		ft_putchar((nbr + '0'), flags, 0);
	else if (nbr < 16)
		ft_putchar(nbr - 10 + 'a', flags, 0);
}


static void	show_adr(uintptr_t adr, char *flags)
{	
	if (!adr)
		ft_putstr("(nil)", flags, 0);
	else
	{
		ft_putchar('0', flags, 0);
		ft_putchar('x', flags, 0);
		memprint(adr, flags);
	}
}

size_t	ptrlen(uintptr_t nbr)
{
	size_t	len;

	len = 2;
	if (!nbr)
		return (6);
	while (nbr != 0)
	{
		nbr = nbr / 16;
		len++;
	}
	return (len);
}
#include <stdio.h>

size_t	putmem(unsigned long long ptr, char *flags)
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
	ret = ptrlen(ptr);
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
