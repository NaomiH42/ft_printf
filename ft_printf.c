/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:49:59 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/20 15:58:35 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
#include <unistd.h>

static size_t	check_per(char c,  va_list args, char *flags)
{
	size_t	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar(va_arg(args, int), flags, 1);
	if (c == 's')
		len = ft_putstr(va_arg(args, char*), flags, 1);
	if (c == 'p')
		len = putmem(va_arg(args, void*), flags);
	if (c == 'd' || c == 'i')
		len = ft_putnbr(va_arg(args, int), flags);
	if (c == 'u')
		len = ft_putnbrun(va_arg(args, unsigned int), flags);			
	if (c == 'x')
		hexalow(va_arg(args, int), flags);	
	if (c == 'X')
		hexaup(va_arg(args, int), flags);	
	if (c == '%')
		len = perc();
	return (len);
}

static size_t	flag_mal(const char *s, size_t i)
{
	int	len;

	len = 0;
	while (s[i] != 'c' && s[i] != 's' && s[i] != 'p' && s[i] != 'd' && s[i] != 'i' && 
			s[i] != 'u' && s[i] != 'x' && s[i] != 'X' && s[i] != '%')
	{
		i++;
		len++;
	}
	return (len);
}
int	ft_printf(const char *s, ...)
{
	size_t	i;
	va_list	args;
	char	*flags;
	int	len;
	size_t	l;
	size_t	total;

	total = 0;
	i = 0;
	len = 0;
	va_start(args, s);
	while (s[i])
	{
		l = 0;
		if (s[i] == '%')
		{

			i++;
			len = flag_mal(s, i);
			flags = (char *)malloc(sizeof(char) * (len + 1));
			while (len > 0)
			{
				flags[l] = s[i];
				len--;
				l++;
				i++;
			}
			flags[l] = '\0';
			total += check_per(s[i], args, flags);
			i++;
			free(flags);
		}
		else 
		{
			ft_putchar(s[i], flags, 0);
			i++;
			total++;
		}
	}
	va_end(args);
	return (total);
}
