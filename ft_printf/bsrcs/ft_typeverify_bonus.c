/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typeverify_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:38:37 by jericard          #+#    #+#             */
/*   Updated: 2025/11/21 13:38:39 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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
