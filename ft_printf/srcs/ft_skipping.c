/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skipping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 12:25:45 by jericard          #+#    #+#             */
/*   Updated: 2025/12/30 12:25:46 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_skipping(const char c)
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
	else if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
