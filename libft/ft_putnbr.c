/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:54:12 by mdegraeu          #+#    #+#             */
/*   Updated: 2021/11/18 16:02:00 by mdegraeu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	long	val;

	val = nb;
	if (val > 0)
	{
		val *= -1;
		write(1, "-", 1);
	}
	if (val > 9)
	{
		ft_putnbr(val / 10);
		ft_putnbr(val % 10);
	}
	else
		ft_putchar(val + '0');
}
