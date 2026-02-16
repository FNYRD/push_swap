/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_0xchar_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:05:54 by jericard          #+#    #+#             */
/*   Updated: 2025/11/06 13:05:56 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_count_0xchar(unsigned long long n)
{
	if (n > 0)
	{
		n = n / 16;
		return (1 + (ft_count_0xchar(n)));
	}
	return (0);
}
