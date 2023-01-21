/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:51:23 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/22 00:14:28 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prnum(int n, char *flags)
{
	char	num;

	if (n == -2147483648)
	{
		ft_putchar('-', flags, 0);
		ft_putchar('2', flags, 0);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-', flags, 0);
		n *= -1;
	}
	if (n >= 10)
	{
		prnum(n / 10, flags);
		prnum(n % 10, flags);
	}
	else
	{
		num = n + '0';
		ft_putchar(num, flags, 0);
	}
}

int	numlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}
#include <stdio.h>

size_t	ft_putnbr(int n, char *flags)
{
	int	after;
	int	before;
	int	dots;
	int	ret;
	int	zeros;

	ret = numlen(n);
	after = minus(flags) - numlen(n);
	before = space(flags) - numlen(n);
	dots = dot(flags) - numlen(n);
	zeros = zero(flags) - numlen(n);
	if (is_in('.', flags) && n == 0 && dots < 0)
	{
		ret = ft_putstr("", flags, 1);
		return (ret);
	}
	if (before > 0)
	{
		if (n < 0 && dots > 0)
			before--;
		if (n < 0 && (dot(flags) - numlen(n) == 0))
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
	if (dots == 0 && numlen(n) != 0 && n < 0)
	{
		ft_putchar('-', flags, 0);
		ret += ft_putchar('0', flags, 0);
		n *= -1;
	}
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
	prnum(n, flags);
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
