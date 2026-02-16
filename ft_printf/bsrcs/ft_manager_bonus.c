/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manager_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:28:02 by jericard          #+#    #+#             */
/*   Updated: 2025/11/21 13:28:06 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

static size_t	padding(const char *data, const char *format)
{
	int		width;
	int		flag;
	int		precision;
	char	type;

	type = ft_datatype(format);
	precision = ft_precision(format);
	flag = ft_flag(format);
	width = ft_width(format);
	if (!data)
		return (0);
	if (precision == 0 && data[0] == '0' && !data[1] && type != 'p')
	{
		if (width)
			return (ft_putminzero("", width, flag));
		else
			return (0);
	}
	return (ft_ph(data, precision, flag, width));
}

static size_t	hexapoint(const char *data, const char *format)
{
	char	*temp;
	char	type;
	int		signal;
	size_t	printed;

	signal = ft_signalflag(format);
	type = ft_datatype(format);
	if (type == 'p' && data[0] == '(')
		return (padding(data, format));
	if (data[0] == '0' && !data[1] && signal >= 10)
		if (type == 'x' || type == 'X')
			return (padding(data, format));
	if (type == 'p' || signal >= 10)
	{
		if (type == 'X')
			temp = ft_strjoin("0X", data);
		else
			temp = ft_strjoin("0x", data);
		printed = padding(temp, format);
		free(temp);
		return (printed);
	}
	(void)temp;
	return (padding(data, format));
}

static size_t	numbers(const char *data, const char *format, char type)
{
	char	*temp;
	size_t	printed;

	temp = NULL;
	if ((type == 'd' || type == 'i') && data[0] != '-' )
	{
		if (ft_signalflag(format) == 1)
			temp = ft_strjoin(" ", data);
		else if (ft_signalflag(format) == 2)
			temp = ft_strjoin("+", data);
		if (temp)
		{
			printed = padding(temp, format);
			free(temp);
			return (printed);
		}
	}
	(void)temp;
	return (padding(data, format));
}

size_t	ft_manager(const char *data, const char *format)
{
	char	type;

	type = ft_datatype(format);
	if (type == 'd' || type == 'u' || type == 'i')
		return (numbers(data, format, type));
	else if (type == 'x' || type == 'X' || type == 'p')
		return (hexapoint(data, format));
	else if (type == 'c' || type == 's' || type == '%')
		return (ft_onlywods(data, format, type));
	else
		return (0);
}
