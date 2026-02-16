/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dotcase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 12:23:10 by jericard          #+#    #+#             */
/*   Updated: 2025/12/30 12:23:11 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	v_s(const char *str)
{
	if (str[0] == '-' || str[0] == ' ' || str[0] == '+')
		return (1);
	return (0);
}

static size_t	h(const char *str, size_t p, size_t precision, size_t flag)
{
	size_t	len;

	if (p < precision)
	{
		precision = p;
	}
	p -= precision;
	len = p;
	if (flag)
	{
		len += ft_putminzero(str, precision + v_s(str), 0);
		while (p-- > 0)
			ft_putchar(' ');
	}
	else
	{
		while (p-- > 0)
			ft_putchar(' ');
		len += ft_putminzero(str, precision + v_s(str), 0);
	}
	return (len);
}

size_t	ft_dotcase(const char *str, size_t p, size_t precision, size_t flag)
{
	size_t	len;
	size_t	prefix;

	len = ft_strlen(str);
	prefix = 0;
	if (str[0] == '-' || str[0] == ' ' || str[0] == '+')
		prefix = 1;
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		prefix = 2;
	if ((p > len) && (p > precision))
	{
		if (precision < (len - prefix))
			precision = len - prefix;
		return (h(str, (p - prefix), precision, flag));
	}
	else
	{
		if (str[0] == '-' || str[0] == ' ' || str[0] == '+')
		{
			ft_putchar(str[0]);
			return (1 + ft_putminzero(str + 1, precision, 0));
		}
		return (ft_putminzero(str, precision, 0));
	}
}
