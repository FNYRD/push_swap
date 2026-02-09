/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:47:10 by jericard          #+#    #+#             */
/*   Updated: 2025/10/29 15:47:11 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*to;
	const unsigned char	*from;

	if (!dest && !src)
		return (dest);
	to = (unsigned char *)dest;
	from = (unsigned char *)src;
	if (to > from)
		while (n--)
			*(to + n) = *(from + n);
	else
		while (n--)
			*to++ = *from++;
	return (dest);
}
