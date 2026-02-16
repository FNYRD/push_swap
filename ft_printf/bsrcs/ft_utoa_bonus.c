/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:24:49 by jericard          #+#    #+#             */
/*   Updated: 2025/11/06 17:24:50 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static size_t	counting(unsigned int num)
{
	size_t	len;

	len = 0;
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static void	writing(char *s, size_t	*i, unsigned int num)
{
	if (num > 9)
		writing(s, i, (num / 10));
	s[*i] = (num % 10) + '0';
	(*i)++;
}

char	*ft_utoa(unsigned int num)
{
	size_t	i;
	size_t	len;
	char	*s;

	i = 0;
	if (num == 0)
		len = 1;
	else
		len = counting(num);
	s = (char *)malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	writing(s, &i, num);
	s[len] = '\0';
	return (s);
}
