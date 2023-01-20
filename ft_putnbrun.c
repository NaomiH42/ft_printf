/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:56:35 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/20 20:45:19 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prnumun(unsigned int n, char *flags)
{
	char	num;

	if (n >= 10)
	{
		prnumun(n / 10, flags);
		prnumun(n % 10, flags);
	}
	else
	{
		num = n + '0';
		ft_putchar(num, flags, 0);
	}
}

int	numlenun(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

size_t	ft_putnbrun(unsigned int n, char *flags)
{
	int	after;
	int	before;
	int	dots;
	size_t	ret;

	ret = numlenun(n);
	after = minus(flags) - numlenun(n);
	before = space(flags) - numlenun(n);
	dots = dot(flags) - numlenun(n);
	if (is_in('+', flags))
		ret +=	ft_putchar('+', flags, 0);
	else if (is_in(' ', flags))
		ret +=ft_putchar(' ', flags, 0);
	else if (before > 0)
		ret += put_space(before);
	else if (is_in('.', flags) && dots > 0)
	{
		ret += put_zero(dots);
	}
	prnumun(n, flags);
	if (!is_in('+', flags) && !is_in(' ', flags) && !is_in('.', flags) && after > 0)
		ret += put_space(after);
	return (ret);
}
