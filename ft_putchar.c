/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehasalu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:51:14 by ehasalu           #+#    #+#             */
/*   Updated: 2023/01/19 19:22:50 by ehasalu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_putchar(char c, char *flags, int test)
{
	int	before;
	int	after;
	size_t	ret;

	if (test == 1)
	{
		before = space(flags) - 1;
		after = minus(flags) - 1;
		if (before > 0)
			ret = put_space(before) + 1;
	}
	write(1, &c, 1);
	if (test == 1)
	{
		if (after > 0)
			ret = put_space(after) + 1;
	}
	return (ret);
}

