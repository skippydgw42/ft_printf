/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:12:31 by mdegraeu          #+#    #+#             */
/*   Updated: 2021/11/18 18:05:40 by mdegraeu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"
//#include "libft.h"

void	ft_dispatch(char c, va_list args)
{
	if (c == 'c')
		ft_putchar((char)va_arg (args, int));
	else if (c == 's')
		ft_putstr(va_arg (args, char *));
	else if (c == 'd')
		ft_putnbr(va_arg (args, int));
	else if (c == 'i')
		ft_putnbr(va_arg (args, int));
	else if (c == 'u')
		ft_putnbr_u(va_arg (args, unsigned int));
	else if (c == 'x')
		ft_putnbr_base(va_arg (args, unsigned int));
	//pas encore bon %p
	else if (c == 'p')
	{
		write(1, "0x", 2);
		ft_putnbr_lu((unsigned long int)va_arg (args, void *));
	}
	else if (c == '%')
		ft_putchar('%');
}

int ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start (args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			ft_dispatch(format[i], args);
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end (args);
	return (0);
}

int	main()
{
	char			c = 'a';
	int				i = 42;
	char			*str = "tout le monde";
	unsigned int	u = 4294967295;

	//===========ft_printf========================//
	ft_printf("\nft_printf function : \n\n");
	ft_printf("bonjour %c %s, je suis a l'ecole %d comme j'imagine 50%% des dev\n", c, str, i);
	ft_printf("un exemple de u_int : %u\n", u);
	ft_printf("un entier hexa non sign : %x\n", u);
	ft_printf("l'adresse memoire en hexa est : %p\n", str);
	ft_printf("\n");

	//===========real printf======================//
	printf("real printf function : \n\n");
	printf("bonjour %c %s, je suis a l'ecole %d comme j'imagine 50%% des dev\n", c, str, i);
	printf("un exemple de u_int : %u\n", u);
	printf("un entier hexa non sign : %x\n", u);
	printf("l'adresse memoire en hexa est : %p\n", str);
	printf("\n");
}
