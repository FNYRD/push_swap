/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_onlywods_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:38:52 by jericard          #+#    #+#             */
/*   Updated: 2025/11/19 15:38:55 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	printing_words(const char *data, const char *format, int flag)
{
	if (flag == 2)
		flag = 1;
	else if (flag == 3 || flag == 0)
		flag = -1;
	return (ft_ph(data, ft_strlen(data), flag, ft_width(format)));
}

static size_t	precision_string(const char *data, const char *format)
{
	int			flag;
	size_t		return_n;
	char		*shortstring;
	size_t		precision;

	precision = ft_precision(format);
	flag = ft_flag(format);
	if ((precision < ft_strlen(data)) && (flag == 2 || flag == 3))
	{
		shortstring = ft_substr(data, 0, precision);
		return_n = printing_words(shortstring, format, flag);
		free(shortstring);
		return (return_n);
	}
	(void)shortstring;
	(void)return_n;
	return (printing_words(data, format, flag));
}

static size_t	null_char(int flag, const char *format)
{
	size_t	printed;
	int		width;

	width = ft_width(format);
	if (width > 0)
		width--;
	if (flag == 2 || flag == 1)
	{
		ft_putchar('\0');
		printed = (ft_putminzero("", width, 1) + 1);
	}
	else if (flag == 3 || flag == -1 || flag == 0)
	{
		printed = (ft_putminzero("", width, -1) + 1);
		ft_putchar('\0');
	}
	else
		printed = ft_putchar('\0');
	return (printed);
}

size_t	ft_onlywods(const char *data, const char *format, char type)
{
	int	flag;

	flag = ft_flag(format);
	if (type == 's')
		return (precision_string(data, format));
	else if (type == 'c')
	{
		if (data[0] == '\0')
			return (null_char(flag, format));
		return (printing_words(data, format, flag));
	}
	else if (type == '%')
	{
		return (ft_putstr(data));
	}
	return (0);
}
