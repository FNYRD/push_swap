/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putminzero_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:07:28 by jericard          #+#    #+#             */
/*   Updated: 2025/11/06 13:07:30 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	printing_padding(const char *str, size_t positions, size_t flag)
{
	if (flag == 1)
	{
		ft_putstr(str);
		while (positions-- > 0)
			ft_putchar(' ');
	}
	else if (flag == 0)
	{
		while (positions-- > 0)
			ft_putchar('0');
		ft_putstr(str);
	}
	else
	{
		while (positions-- > 0)
			ft_putchar(' ');
		ft_putstr(str);
	}
}

static const char	*hp(size_t flag, const char *str, size_t *printed)
{
	if (flag == 0 || flag == 1)
	{
		ft_putchar('0');
		ft_putchar(str[1]);
		*printed += 2;
		return (str + 2);
	}
	return (str);
}

static const char	*direction(size_t flag, const char *str, size_t *printed)
{
	if (str[1] == 'x' || str[1] == 'X')
		return (hp(flag, str, printed));
	else if (flag == 0 || flag == 1)
	{
		ft_putchar(str[0]);
		*printed += 1;
		return (str + 1);
	}
	return (str);
}

size_t	ft_putminzero(const char *str, size_t positions, size_t flag)
{
	size_t		len;
	size_t		printed;
	const char	*ptr;

	printed = 0;
	len = ft_strlen(str);
	if (positions <= len)
	{
		ft_putstr(str);
		return (len);
	}
	if (str[0] == '-' && (flag == 1 || flag == 0))
	{
		ptr = &str[1];
		ft_putchar('-');
		printed++;
	}
	else if (len > 1 && (str[0] == '0' || str[0] == ' ' || str[0] == '+'))
		ptr = direction(flag, str, &printed);
	else
		ptr = str;
	printing_padding(ptr, (positions -= len), flag);
	return (printed + positions + ft_strlen(ptr));
}
