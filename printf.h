/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:50:49 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/19 00:20:31 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_putchar(char c, char *flags, int test);
void	ft_putstr(char *s, char *flags, int test);
void	ft_putnbr(int n, char *flags);
void	ft_putnbrun(unsigned int n, char *flags);
void	hexalow(int nbr, char *flags);
void	hexaup(int nbr, char *flags);
void	putmem(void *ptr, char *flags);
int	ft_printf(const char *s, ...);
size_t	ft_strlen(const char *s);

#endif
