/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_datatype_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:27:10 by jericard          #+#    #+#             */
/*   Updated: 2025/11/21 13:27:12 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	ft_datatype(const char *ptr)
{
	int	i;

	i = 0;
	while (ft_skipping(ptr[i]))
		i++;
	return (ptr[i]);
}
