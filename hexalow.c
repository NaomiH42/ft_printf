/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexalow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:16:02 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/19 00:21:20 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	hexalow(int nbr, char *flags)
{
	int	length;
	char	*base;

	base = "0123456789abcdef";
	length = 16;
	
	if (nbr < 0)
	{
		ft_putchar('-', flags, 0);
		nbr *= -1;
	}
	if (nbr >= length)
	{
		hexalow(nbr / length, flags);
		hexalow(nbr % length, flags);
	}
	if (nbr < length)
		ft_putchar(base[nbr], flags, 0);
}
