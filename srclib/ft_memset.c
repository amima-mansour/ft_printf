/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 16:51:48 by amansour          #+#    #+#             */
/*   Updated: 2017/09/18 13:53:03 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t		i;
	char		*str;

	i = 0;
	str = (char*)s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}
