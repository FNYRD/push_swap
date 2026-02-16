/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_helper_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:29:16 by jericard          #+#    #+#             */
/*   Updated: 2025/11/21 13:29:18 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_ph(const char *data, int precision, int flag, long long width)
{
	if (flag == 0 || (flag < 0 && width))
		return (ft_putminzero(data, width, flag));
	else if (flag == 1)
		return (ft_putminzero(data, width, flag));
	else if (flag == 2)
		return (ft_dotcase(data, width, precision, 1));
	else if (flag == 3)
		return (ft_dotcase(data, width, precision, 0));
	else
		ft_putstr(data);
	return (ft_strlen(data));
}
