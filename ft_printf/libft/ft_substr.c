/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:53:09 by jericard          #+#    #+#             */
/*   Updated: 2025/10/29 15:53:11 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*allocating(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	real_space;

	if ((ft_strlen(s) - (size_t)start) < len)
		real_space = ft_strlen(s) - (size_t)start;
	else
		real_space = len;
	new = malloc(real_space * sizeof(char) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		new[i] = s[start];
		i++;
		start++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;

	if (!s)
		return (NULL);
	if ((size_t)start >= ft_strlen(s) || len == 0)
	{
		new = malloc(1);
		if (!new)
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	return (allocating(s, start, len));
}
