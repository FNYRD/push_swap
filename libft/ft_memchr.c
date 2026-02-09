/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:48:21 by jericard          #+#    #+#             */
/*   Updated: 2025/10/29 15:48:23 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s1;

	s1 = (const unsigned char *)s;
	while (n > 0)
	{
		if (*s1 == (unsigned char)c)
			return ((void *)s1);
		n--;
		s1++;
	}
	return (NULL);
}
