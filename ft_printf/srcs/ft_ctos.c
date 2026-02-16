/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 12:22:43 by jericard          #+#    #+#             */
/*   Updated: 2025/12/30 12:22:45 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
