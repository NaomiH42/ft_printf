/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexaup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:16:02 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/21 14:28:22 by ehasalu          ###   ########.fr       */
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

size_t	hexaup(int n, char *flags)
{
	int	after;
	int	before;
	int	dots;
	int	ret;
	int	zeros;

	ret = hexauplen(n);
	after = minus(flags) - hexauplen(n);
	before = space(flags) - hexauplen(n);
	dots = dot(flags) - hexauplen(n);
	zeros = zero(flags) - hexauplen(n);

	if (is_in('.', flags) && n == 0 && dots < 0)
	{
		ret = ft_putstr("", flags, 1);
		return (ret);
	}	
	if (before > 0)
	{
		if (n < 0 && dots > 0)
			before--;
		if (dots > 0)
			before -= dots;
		zeros -= before;
		if (before > 0)
			ret += put_space(before);
	}
	if (flags[0] == '0' && zeros > 0)
	{
		if(n < 0)
		{
			ft_putchar('-', flags, 0);
			n *= -1;
		}
		dots = 0;
		ret += put_zero(zeros);
	}
	else if (is_in('+', flags) && n >= 0)
		ret += ft_putchar('+', flags, 0);
	else if (is_in(' ', flags) && n >= 0)
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
		if (n < 0)
		{
			ft_putchar('-', flags, 0);
			n = n * -1;
			ret += put_zero(dots + 1);
			dots++;
		}
		else
			ret += put_zero(dots);
	}
	hexaupprint(n, flags);
	if (!is_in('+', flags) && !is_in(' ', flags) && after > 0)
	{
		if (n < 0 && dots > 0)
			after--;
		if (dots > 0)
			after -= dots;
		ret += put_space(after);
	}
	return (ret);
}
