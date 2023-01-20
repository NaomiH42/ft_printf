/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexaup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:16:02 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/20 20:33:00 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	hexauplen(int nbr)
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


void	hexaupprint(int nbr, char *flags)
{
	if (nbr == -2147483648)
	{
		ft_putstr("80000000", flags, 0);
		return;
	}
	else if (nbr == 2147483647)
	{
		ft_putstr("7FFFFFFF", flags, 0);
		return;
	}
	else if (nbr < 0)
	{
		ft_putchar('F', flags, 0);
		nbr += 268435456;
	}
	if (nbr >= 16)
	{
		hexaupprint(nbr / 16, flags);
		hexaupprint(nbr % 16, flags);
	}
	else if (nbr <= 9)
		ft_putchar((nbr + '0'), flags, 0);
	else if (nbr < 16)
		ft_putchar(nbr - 10 + 'A', flags, 0);
}

size_t	hexaup(int nbr, char *flags)
{
	size_t	len;

	len = hexauplen(nbr);
	hexaupprint(nbr, flags);
	return (len);
}
