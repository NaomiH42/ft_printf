/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:56:35 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/18 13:18:39 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbrun(unsigned int n)
{
	char	num;

	if (n >= 10)
	{
		ft_putnbrun(n / 10);
		ft_putnbrun(n % 10);
	}
	else
	{
		num = n + '0';
		ft_putchar(num);
	}
}
