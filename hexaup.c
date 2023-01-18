/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexaup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:16:02 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/19 00:21:02 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	hexaup(int nbr, char *flags)
{
	int	length;
	char	*base;

	base = "0123456789ABCDEF";
	length = 16;
	
	if (nbr < 0)
	{
		ft_putchar('-', flags, 0);
		nbr *= -1;
	}
	if (nbr >= length)
	{
		hexaup(nbr / length, flags);
		hexaup(nbr % length, flags);
	}
	if (nbr < length)
		ft_putchar(base[nbr], flags, 0);
}
