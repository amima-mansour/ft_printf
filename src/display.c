/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 11:36:55 by amansour          #+#    #+#             */
/*   Updated: 2017/09/29 10:14:23 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

static void		n_write(int n, char c)
{
	while (n--)
		write(1, &c, 1);
	return ;
}

int			display_char(char c, t_format format)
{
	char l;

	format.width = (!format.width) ? 1 : format.width;
	l = (format.flag & LEADZEROFLAG) ? '0' : ' ';
	if (format.flag & LEFTFORMATFLAG)
	{
		ft_putchar(c);
		n_write(format.width - 1, ' ');
	}
	else
	{
		n_write(format.width - 1, l);
		ft_putchar(c);
	}
	return (format.width);
}

int			display(char *str, t_format format)
{
	int		len;
	char    c;

	if (format.width < 0)
	{
		format.flag |= LEFTFORMATFLAG;
		format.width = -format.width;
	}
	c = (!belong(format.c, "dDiuUxXoO") &&
			(format.flag & LEADZEROFLAG)) ? '0' : ' ';
	len = (!(*str) && (format.c == 'c' || format.c == 'C')) ? 1 : ft_strlen(str);
	if (format.width > len)
	{
		if (format.flag & LEFTFORMATFLAG)
		{
			write(1, str, len);
			n_write(format.width - len, ' ');
		}
		else if (!belong(format.c, "sScC%") && (format.flag & LEADZEROFLAG)
				&& format.precision < 0)
			write(1, str, len);
		else
		{
			n_write(format.width - len, c);
			write(1, str, len);
		}
	}
	else
		write(1, str, len);
	return ((len < format.width) ? format.width : len);
}
