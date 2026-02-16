/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:49:03 by jericard          #+#    #+#             */
/*   Updated: 2026/02/09 20:49:05 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	mvs(int target, int target_top, int tail)
{
	int	line;
	int	cost;

	cost = 0;
	line = ((tail + 1) - target_top) / 2 + target_top;
	if (target == target_top + 1)
		cost = 1;
	else if (target <= line)
		cost = target - target_top;
	else if (target > line)
		cost = (tail - target) + 1;
	return (cost);
}

int	magic(int a, int b, int flag)
{
	if (flag == 1)
	{
		if (a > b)
			return (a);
		return (b);
	}
	else if (flag == 2)
		return (((a + 1) - b) / 2 + b);
	if (a < b)
		return (a);
	return (b);
}

int	move(int point_a, int point_b, int line_a, int line_b)
{
	if ((point_a == line_a) || (point_b == line_b))
		return (1);
	else if ((point_a > line_a) && (point_b > line_b))
		return (1);
	else if ((point_a < line_a) && (point_b < line_b))
		return (1);
	return (0);
}

static int	cost(int pt, int tg, int *tops, int tail)
{
	int	la;
	int	lb;
	int	ca;
	int	cb;

	ca = mvs(pt, tops[0], tail);
	cb = mvs(tg, tops[1], tail);
	la = magic(tail, tops[0], 2);
	lb = magic(tail, tops[1], 2);
	if (move(pt, tg, la, lb))
		return (magic(ca, cb, 1));
	return (ca + cb);
}

int	best_costs(int *stack_a, int *stack_b, int *tops, int tail)
{
	int	tg;
	int	pt;
	int	best_cost;
	int	best_pt;

	best_cost = INT_MAX;
	best_pt = tops[0];
	pt = tops[0] - 1;
	while (++pt <= tail)
	{
		tg = fnd_target_a(stack_a[pt], stack_b, tops[1], tail);
		if (cost(pt, tg, tops, tail) < best_cost)
		{
			best_pt = pt;
			best_cost = cost(pt, tg, tops, tail);
		}
	}
	return (best_pt);
}
