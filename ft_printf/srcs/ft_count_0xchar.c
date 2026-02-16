/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_0xchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 12:22:28 by jericard          #+#    #+#             */
/*   Updated: 2025/12/30 12:22:30 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_0xchar(unsigned long long n)
{
	if (n > 0)
	{
		n = n / 16;
		return (1 + (ft_count_0xchar(n)));
	}
	return (0);
}
