/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 12:26:01 by jericard          #+#    #+#             */
/*   Updated: 2025/12/30 12:26:03 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*helper(va_list *arg, const char *format)
{
	char	*ptr;
	int		precision;

	ptr = va_arg(*arg, char *);
	precision = ft_precision(format);
	if (ptr == NULL)
	{
		if (precision >= 0 && precision < 6)
			return (ft_strdup(""));
		return (ft_strdup("(null)"));
	}
	return (ft_strdup(ptr));
}

static char	*charter(const char c, va_list *arg)
{
	if (c == '%')
	{
		(void)arg;
		return (ft_ctos('%'));
	}
	return (ft_ctos(((char)va_arg(*arg, int))));
}

char	*ft_stringer(const char c, va_list *arg, const char *format)
{
	void	*p;

	if (c == 's')
		return (helper(arg, format));
	(void)format;
	if (c == 'x' || c == 'X')
		return (ft_hexa(va_arg(*arg, unsigned int), c));
	else if (c == 'u')
		return (ft_utoa(va_arg(*arg, unsigned int)));
	else if (c == 'd' || c == 'i')
		return (ft_itoa(va_arg(*arg, int)));
	else if (c == 'c' || c == '%')
		return (charter(c, arg));
	else if (c == 'p')
	{
		p = va_arg(*arg, void *);
		if (!p)
			return (ft_strdup("(nil)"));
		return (ft_hexa((unsigned long long)p, 'x'));
	}
	return (NULL);
}
