/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:47:28 by jericard          #+#    #+#             */
/*   Updated: 2025/10/29 15:47:30 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	available;
	size_t	dst_len;
	size_t	src_len;
	size_t	ret;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	ret = dst_len + src_len;
	if (size <= dst_len)
		return (size + src_len);
	available = size - dst_len - 1;
	i = 0;
	while (src[i] && available > 0)
	{
		dst[dst_len] = src[i];
		i++;
		dst_len++;
		available--;
	}
	dst[dst_len] = '\0';
	return (ret);
}
