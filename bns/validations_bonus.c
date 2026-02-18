/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:34:57 by jericard          #+#    #+#             */
/*   Updated: 2026/02/18 15:34:58 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_isvalid(int c, int next, int pos)
{
	if ((c >= '0' && c <= '9') || c == '-' || c == '+')
	{
		if (c == '-' || c == '+')
		{
			if (pos != 0 || !(next >= '0' && next <= '9'))
				return (0);
		}
		return (1);
	}
	return (0);
}

int	matriz_len(char **matriz, int index)
{
	int	len;

	len = 0;
	while (matriz[len])
		len++;
	if (index == 1)
		len--;
	return (len);
}

int	non_duplicate(int *new_array, int len)
{
	int	i;
	int	to_compare;

	to_compare = 1;
	while (to_compare < len)
	{
		i = 0;
		while (i < len)
		{
			if (new_array[i] == new_array[to_compare] && i != to_compare)
				return (0);
			i++;
		}
		to_compare++;
	}
	return (1);
}

void	error(char **matriz, int mi)
{
	int		i;
	int		len;
	char	**to_free;

	if (mi == 1)
		to_free = NULL;
	else
		to_free = matriz;
	if (!matriz[mi])
		ft_exit(to_free);
	while (matriz[mi])
	{
		i = 0;
		len = ft_strlen(matriz[mi]);
		if (len == 0)
			ft_exit(to_free);
		while (i < len)
		{
			if (!(ft_isvalid(matriz[mi][i], matriz[mi][i + 1], i)))
				ft_exit(to_free);
			i++;
		}
		mi++;
	}
}
