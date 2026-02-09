/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:53:59 by jericard          #+#    #+#             */
/*   Updated: 2025/10/29 15:54:00 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	counting(int n)
{
	size_t	len;
	long	num;

	len = 0;
	if (n < 0)
	{
		num = (-(long)n);
		len++;
	}
	else
		num = (long)n;
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	if (n == 0)
		len++;
	return (len);
}

static void	writing(char *s, size_t	*i, long num)
{
	if (num > 9)
		writing(s, i, (num / 10));
	s[*i] = (num % 10) + '0';
	(*i)++;
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	len;
	char	*s;
	long	num;

	i = 0;
	len = counting(n);
	num = 0;
	s = (char *)malloc((len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	if (n < 0)
	{
		s[i] = '-';
		num = (-(long)n);
		i++;
	}
	else
		num = (long)n;
	writing(s, &i, num);
	s[len] = '\0';
	return (s);
}
