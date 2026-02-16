/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 12:23:36 by jericard          #+#    #+#             */
/*   Updated: 2025/12/30 12:23:37 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*helper(void)
{
	char	*p;

	p = malloc(2);
	if (!p)
		return (NULL);
	p[0] = '0';
	p[1] = '\0';
	return (p);
}

static unsigned int	ft_capital(const char x)
{
	unsigned int	capital;

	if (x == 'X')
		capital = 7;
	else
		capital = 39;
	return (capital);
}

char	*ft_hexa(unsigned long long n, const char x)
{
	unsigned int	res;
	unsigned int	capital;
	unsigned int	len;
	char			*p;

	if (n == 0)
		return (helper());
	len = ft_count_0xchar(n);
	p = malloc(len * sizeof(char) + 1);
	if (!p)
		return (NULL);
	capital = ft_capital(x);
	p[len--] = '\0';
	while (n > 0)
	{
		res = n % 16;
		n = n / 16;
		if (res >= 10)
			p[len--] = ((res + '0') + capital);
		else
			p[len--] = (res + '0');
	}
	return (p);
}
