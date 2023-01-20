/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:50:49 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/20 15:58:46 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	is_in(char c, char *flags);
size_t	put_zero(size_t n);
size_t	put_space(size_t n);
size_t	ft_putchar(char c, char *flags, int test);
size_t	ft_putstr(char *s, char *flags, int test);
size_t	ft_putnbr(int n, char *flags);
size_t	ft_putnbrun(unsigned int n, char *flags);
void	hexalow(int nbr, char *flags);
void	hexaup(int nbr, char *flags);
size_t	putmem(void *ptr, char *flags);
int	ft_printf(const char *s, ...);
size_t	ft_strlen(const char *s);
size_t	perc(void);
size_t	dot(char *flags);
size_t	minus(char *flags);
size_t	space(char *flags);

#endif
