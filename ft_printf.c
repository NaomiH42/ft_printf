/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:49:59 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/18 13:34:42 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
#include <unistd.h>

void	check_per(char c,  va_list args)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int));
	if (c == 's')
		ft_putstr(va_arg(args, char*));
	if (c == 'p')
		putmem(va_arg(args, void*));
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int));
	if (c == 'u')
		ft_putnbrun(va_arg(args, unsigned int));			
	if (c == 'x')
		hexalow(va_arg(args, int));	
	if (c == 'X')
		hexaup(va_arg(args, int));	
	if (c == '%')
		ft_putchar('%');
}

int	ft_printf(const char *s, ...)
{
	size_t	i;
	va_list	args;

	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			check_per(s[i + 1], args);
			i += 2;
		}
		else 
		{
			ft_putchar(s[i]);
			i++;
		}
	}
	va_end(args);
	return (1);
}
