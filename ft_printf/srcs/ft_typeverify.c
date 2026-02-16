/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typeverify.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 12:26:12 by jericard          #+#    #+#             */
/*   Updated: 2025/12/30 12:26:13 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_typeverify(char c)
{
	if (c == 'd')
		return (1);
	else if (c == 'i')
		return (1);
	else if (c == 'u')
		return (1);
	else if (c == 'c')
		return (1);
	else if (c == 's')
		return (1);
	else if (c == 'X')
		return (1);
	else if (c == 'x')
		return (1);
	else if (c == 'p')
		return (1);
	else if (c == '%')
		return (1);
	return (0);
}
