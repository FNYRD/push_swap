/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:11:15 by jericard          #+#    #+#             */
/*   Updated: 2025/11/07 15:11:17 by jericard         ###   ########.fr       */
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
	else if (c == '-')
		return (1);
	else if (c == '+')
		return (1);
	else if (c == '0')
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_width(const char *str)
{
	int	i;
	int	width;

	width = 0;
	i = 0;
	while (verifyer(str[i]))
	{
		if (str[i] == '.')
			break ;
		if ((str[i] >= '1' && str[i] <= '9') && width == 0)
			width = (str[i] - '0');
		else if ((str[i] >= '0' && str[i] <= '9') && width > 0)
			width = (width * 10) + (str[i] - '0');
		i++;
	}
	return (width);
}
