/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:31:27 by jericard          #+#    #+#             */
/*   Updated: 2025/12/19 12:31:29 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static ssize_t	sender2manager(const char *format, va_list *arg)
{
	char	*data;
	char	type;
	size_t	printed;

	type = ft_datatype(format);
	printed = 0;
	data = ft_stringer(type, arg, format);
	if (!data)
		return (-1);
	else if (ft_skipping(*(format)) || type == 'p' || type == 'c')
		printed = ft_manager(data, format);
	else
		printed = ft_putstr(data);
	free(data);
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	size_t	printed;

	i = 0;
	printed = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			printed += sender2manager(&format[i], &arg);
			while (ft_skipping(format[i]))
				i++;
			if (format[i])
				i++;
			continue ;
		}
		printed += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (printed);
}
