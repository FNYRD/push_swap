/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctos_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:05:27 by jericard          #+#    #+#             */
/*   Updated: 2025/11/06 17:05:29 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_ctos(const char c)
{
	char	*s;

	s = malloc(2 * sizeof(char));
	if (!s)
		return (NULL);
	s[0] = c;
	s[1] = '\0';
	return (s);
}
