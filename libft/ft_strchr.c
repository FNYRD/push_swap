/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:47:55 by jericard          #+#    #+#             */
/*   Updated: 2025/10/29 15:47:56 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)c == (unsigned char)*s)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == (unsigned char)*s)
		return ((char *)s);
	return (NULL);
}
