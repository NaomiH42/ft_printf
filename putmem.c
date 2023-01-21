/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putmem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:01:56 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/21 14:49:59 by ehasalu          ###   ########.fr       */
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
		return (5);
	while (nbr != 0)
	{
		nbr = nbr / 16;
		len++;
	}
	return (len);
}
#include <stdio.h>

size_t	putmem(unsigned long long n, char *flags)
{
	int	after;
	int	before;
	int	dots;
	int	ret;
	int	zeros;

	ret = ptrlen(n);
	after = minus(flags) - ptrlen(n);
	before = space(flags) - ptrlen(n);
	dots = dot(flags) - ptrlen(n);
	zeros = zero(flags) - ptrlen(n);

	if (is_in('.', flags) && n == 0 && dots < 0)
	{
		ret = ft_putstr("", flags, 1);
		return (ret);
	}	
	if (before > 0)
	{
		if (dots > 0)
			before -= dots;
		zeros -= before;
		ret += put_space(before);
	}
	if (flags[0] == '0' && zeros > 0)
	{
		dots = 0;
		ret += put_zero(zeros);
	}
	else if (is_in('+', flags))
		ret += ft_putchar('+', flags, 0);
	else if (is_in(' ', flags) && n == 0)
		ret += ft_putchar(' ', flags, 0);
//	else if (before > 0)
//	{
//		if (n < 0 && dots > 0)
//			before--;
//		if (dots > 0)
//			before -= dots;
//		ret += put_space(before);
//	}
	if (is_in('.', flags) && dots > 0)
	{
		ret += put_zero(dots);
	}
	show_adr(n, flags);
	if (!is_in('+', flags) && !is_in(' ', flags) && after > 0)
	{
		if (dots > 0)
			after -= dots;
		ret += put_space(after);
	}
	return (ret);
}
