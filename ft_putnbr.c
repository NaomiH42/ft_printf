/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:51:23 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/19 00:43:15 by ehasalu          ###   ########.fr       */
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
/*
int	is_in(char c, char *flags)
{
	size_t	i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count(char *flags, size_t i)
{
	size_t	i;
	
	i = 0;
	while (flags[i])
	{
		
	}
}
*/
void	ft_putnbr(int n, char *flags)
{
	prnum(n, flags);
	//size_t	i;

	//i = 0;
	//if (flags[0] >= '1' && flags[0] <= '9')
	//{

	//}
}
