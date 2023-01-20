/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:51:23 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/20 16:00:46 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

size_t	ft_putnbr(int n, char *flags)
{
	int	after;
	int	before;
	int	dots;
	int	ret;

	ret = numlen(n);
	after = minus(flags) - numlen(n);
	before = space(flags) - numlen(n);
	dots = dot(flags) - numlen(n);
	if (is_in('+', flags) && n >= 0)
		ret += ft_putchar('+', flags, 0);
	else if (is_in(' ', flags) && n >= 0)
		ret += ft_putchar(' ', flags, 0);
	else if (before > 0)
		ret += put_space(before);
	else if (is_in('.', flags) && dots > 0)
	{
		if (n < 0)
		{
			ft_putchar('-', flags, 0);
			n = n * -1;
		}
		ret += put_zero(dots);
	}
	prnum(n, flags);
	if (!is_in('+', flags) && !is_in(' ', flags) && !is_in('.', flags) && after > 0)
		ret += put_space(after);
	return (ret);
}
