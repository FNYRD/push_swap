/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:53:37 by jericard          #+#    #+#             */
/*   Updated: 2025/10/29 15:53:38 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	is_set(char s1, char const *set)
{
	size_t	j;

	j = 0;
	while (set[j])
	{
		if (set[j] == s1)
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !*s1)
		return (ft_strdup(""));
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && (is_set(s1[start], set)))
		start++;
	while (end > start && (is_set(s1[end], set)))
		end--;
	return (ft_substr(s1, start, (end - start) + 1));
}
