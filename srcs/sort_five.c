/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 12:00:00 by jericard          #+#    #+#             */
/*   Updated: 2026/02/17 12:00:00 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_min(int *stack_a, int *stack_b, int *tops, int tail)
{
	int	min_idx;
	int	min_val;
	int	line;

	min_idx = set_i(stack_a, tops[0], tail, 0);
	min_val = stack_a[min_idx];
	line = magic(tail, tops[0], 2);
	if (min_idx > line)
		while (min_val != stack_a[tops[0]])
			rra(stack_a, tops[0], tail, 0);
	else
		while (min_val != stack_a[tops[0]])
			ra(stack_a, tops[0], tail, 0);
	pb(stack_a, &tops[0], stack_b, &tops[1]);
}

void	sort_5(int *stack_a, int *stack_b, int *tops, int tail)
{
	int	pushes;
	int	i;

	pushes = (tail + 1) - tops[0] - 3;
	i = 0;
	while (i++ < pushes)
		push_min(stack_a, stack_b, tops, tail);
	order_3(stack_a, tops[0]);
	while (pushes-- > 0)
		pa(stack_a, &tops[0], stack_b, &tops[1]);
}
