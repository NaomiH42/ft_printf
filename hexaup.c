/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexaup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:16:02 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/22 00:17:11 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	hexauplen(unsigned int nbr)
{
	size_t	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / 16;
		len++;
	}
	return (len);
}


void	hexaupprint(unsigned int nbr, char *flags)
{
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

size_t	hexaup(unsigned int n, char *flags)
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
		if (dots > 0)
			before -= dots;
		zeros -= before;
		if (before > 0)
			ret += put_space(before);
	}
	if (flags[0] == '0' && zeros > 0)
	{
		dots = 0;
		ret += put_zero(zeros);
	}
	else if (is_in('+', flags))
		ret += ft_putchar('+', flags, 0);
	else if (is_in(' ', flags))
		ret += ft_putchar(' ', flags, 0);
	if (is_in('.', flags) && dots > 0)
	{
		ret += put_zero(dots);
	}
	hexaupprint(n, flags);
	if (!is_in('+', flags) && !is_in(' ', flags) && after > 0)
	{
		if (dots > 0)
			after -= dots;
		ret += put_space(after);
	}
	return (ret);
}
