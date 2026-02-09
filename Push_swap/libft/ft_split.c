/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:53:48 by jericard          #+#    #+#             */
/*   Updated: 2025/10/29 15:53:49 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	counting_words(char const *s, char c)
{
	size_t	i;
	size_t	flag;
	size_t	n_words;

	i = 0;
	flag = 1;
	n_words = 0;
	while (s[i] != '\0')
	{
		if (s[i] && s[i] != c && flag)
		{
			n_words++;
			flag = 0;
		}
		if (s[i] && s[i] == c && !flag)
			flag = 1;
		i++;
	}
	return (n_words);
}

static char	**verify(char const *s)
{
	char	**ptr;

	if (!s)
		return (NULL);
	if (!*s)
	{
		ptr = malloc(sizeof(char *));
		if (!ptr)
			return (NULL);
		ptr[0] = NULL;
		return (ptr);
	}
	ptr = malloc(sizeof(char *) * 2);
	if (!ptr)
		return (NULL);
	ptr[0] = ft_strdup(s);
	if (!ptr[0])
	{
		free(ptr[0]);
		free(ptr);
		return (NULL);
	}
	ptr[1] = NULL;
	return (ptr);
}

static char	**returning_null(char **ptr, int k)
{
	if (k == 0)
		free(ptr[k]);
	else if (k > 0)
	{
		while (--k >= 0)
		{
			free(ptr[k]);
		}
	}
	free(ptr);
	return (NULL);
}

static char	**creating(char **ptr, char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		j = i;
		while (s[j] && s[j] != c)
			j++;
		ptr[k] = ft_substr(s, (unsigned int)i, (j - i));
		if (!ptr[k])
			return (returning_null(ptr, k));
		i = j;
		k++;
	}
	ptr[k] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	len_ptr;

	if (!s || !*s || !c)
		return (verify(s));
	len_ptr = counting_words(s, c);
	ptr = malloc((len_ptr + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	if (len_ptr == 0)
	{
		ptr[0] = NULL;
		return (ptr);
	}
	return (creating(ptr, s, c));
}
