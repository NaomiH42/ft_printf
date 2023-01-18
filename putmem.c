/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putmem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:01:56 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/18 13:13:41 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stddef.h>

static void	hex(unsigned long long nbr)
{
	unsigned long long	length;
	char	*base;

	base = "0123456789abcdef";
	length = 16;
	
	if (nbr >= length)
	{
		hex(nbr / length);
		hex(nbr % length);
	}
	if (nbr < length)
		ft_putchar(base[nbr]);
}

void	putmem(void *ptr)
{	
	unsigned long long	adr;

	adr = (unsigned long long)&ptr;
	if (!ptr)
		ft_putstr("(nil)");
	else
	{
		ft_putchar('0');
		ft_putchar('x');
		hex(adr);
	}
}
