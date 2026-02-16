/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:24:29 by jericard          #+#    #+#             */
/*   Updated: 2025/11/07 16:24:31 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static unsigned int	verifyer(const char c)
{
	if (!c)
		return (0);
	if (c == '#')
		return (1);
	else if (c == ' ')
		return (1);
	else if (c == '.')
		return (1);
	else if (c == '-')
		return (1);
	else if (c == '+')
		return (1);
	else if (c == '0')
		return (1);
	else if (c == '*')
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_precision(const char *str)
{
	int		i;
	int		flag;
	int		precision;

	precision = 0;
	flag = 0;
	i = -1;
	while (verifyer(str[++i]))
	{
		if (str[i] == '.')
			flag = 1;
		else if (flag == 1 && ft_isdigit(str[i]))
			precision = (precision * 10) + (str[i] - '0');
	}
	if (!flag)
		return (-1);
	return (precision);
}
