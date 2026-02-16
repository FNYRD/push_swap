/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   director.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:36:33 by jericard          #+#    #+#             */
/*   Updated: 2026/02/16 15:36:35 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	in_order(int *stack, int top, int tail, int flag)
{
	if (flag == 1)
	{
		while (top < tail)
		{
			if (stack[top] <= stack[top + 1])
				return (0);
			top++;
		}
	}
	else
	{
		while (top < tail)
		{
			if (stack[top] > stack[top + 1])
				return (0);
			top++;
		}
	}
	return (1);
}

static void	pass_a(int *stack_a, int *stack_b, int *tops, int tail)
{
	int	line_a;
	int	target_num;
	int	target;

	line_a = magic(tail, tops[0], 2);
	target = fnd_target_b(stack_b[tops[1]], stack_a, tops[0], tail);
	target_num = stack_a[target];
	if (target > line_a)
		while (target_num != stack_a[tops[0]])
			rra(stack_a, tops[0], tail, 0);
	else
		while (target_num != stack_a[tops[0]])
			ra(stack_a, tops[0], tail, 0);
	pa(stack_a, &tops[0], stack_b, &tops[1]);
}

static void	ordening_a(int *stack_a, int top, int tail)
{
	int	greater_index;
	int	line_b;
	int	greater;

	greater_index = set_i(stack_a, top, tail, 0);
	line_b = magic(tail, top, 2);
	greater = stack_a[greater_index];
	if (greater_index > line_b)
		while (greater != stack_a[top])
			rra(stack_a, top, tail, 0);
	else
		while (greater != stack_a[top])
			ra(stack_a, top, tail, 0);
}

void	director(int *stack_a, int *stack_b, int *tops, int tail)
{
	int	line_b;
	int	greater;
	int	n;

	pb(stack_a, &tops[0], stack_b, &tops[1]);
	if (((tail + 1) - tops[0]) > 3)
		pb(stack_a, &tops[0], stack_b, &tops[1]);
	while (((tail + 1) - tops[0]) > 3)
		manager(stack_a, stack_b, tops, tail);
	line_b = magic(tail, tops[1], 2);
	greater = set_i(stack_b, tops[1], tail, 1);
	n = stack_b[greater];
	if (stack_b[greater] <= stack_b[line_b])
		while (n != stack_b[tops[1]])
			rb(stack_b, tops[1], tail, 0);
	else
		while (n != stack_b[tops[1]])
			rrb(stack_b, tops[1], tail, 0);
	order_3(stack_a, tops[0]);
	if (in_order(stack_b, tops[1], tail, 1))
		while (tops[1] <= tail)
			pass_a(stack_a, stack_b, tops, tail);
	ordening_a(stack_a, tops[0], tail);
	free(stack_a);
	free(stack_b);
}
