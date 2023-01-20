/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexalow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:16:02 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/20 20:29:47 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static size_t	hexalowlen(int nbr)
{
	size_t	len;

	len = 0;
	if (nbr == -2147483648)
		return(8);
	else if (nbr == 2147483647)
		return (8);
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{	
		len++;
		nbr += 268435456;
	}
	while (nbr != 0)
	{
		nbr = nbr / 16;
		len++;
	}
	return (len);
}


void	hexalowprint(int nbr, char *flags)
{
	if (nbr == -2147483648)
	{
		ft_putstr("80000000", flags, 0);
		return;
	}
	else if (nbr == 2147483647)
	{
		ft_putstr("7fffffff", flags, 0);
		return;
	}
	else if (nbr < 0)
	{
		ft_putchar('f', flags, 0);
		nbr += 268435456;
	}
	if (nbr >= 16)
	{
		hexalowprint(nbr / 16, flags);
		hexalowprint(nbr % 16, flags);
	}
	else if (nbr <= 9)
		ft_putchar((nbr + '0'), flags, 0);
	else if (nbr < 16)
		ft_putchar(nbr - 10 + 'a', flags, 0);
}

size_t	hexalow(int nbr, char *flags)
{
	size_t	len;

	len = hexalowlen(nbr);
	hexalowprint(nbr, flags);
	return (len);
}
