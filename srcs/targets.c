/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:25:33 by jericard          #+#    #+#             */
/*   Updated: 2026/02/09 16:25:34 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fnd_target_a(int a, int *b, int tb, int tail)
{
	int	index;
	int	top;

	top = tb;
	index = -1;
	while (tb <= tail)
	{
		if (a > b[tb])
		{
			if (index == -1 || b[tb] > b[index])
				index = tb;
		}
		tb++;
	}
	if (index == -1)
		return (set_i(b, top, tail, 1));
	return (index);
}

int	fnd_target_b(int b, int *a, int ta, int tail)
{
	int	index;
	int	top;

	top = ta;
	index = -1;
	while (ta <= tail)
	{
		if (b < a[ta])
		{
			if (index == -1 || a[ta] < a[index])
				index = ta;
		}
		ta++;
	}
	if (index == -1)
		return (set_i(a, top, tail, 0));
	return (index);
}
