/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_datatype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 12:22:56 by jericard          #+#    #+#             */
/*   Updated: 2025/12/30 12:22:57 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_datatype(const char *ptr)
{
	int	i;

	i = 0;
	while (ft_skipping(ptr[i]))
		i++;
	return (ptr[i]);
}
