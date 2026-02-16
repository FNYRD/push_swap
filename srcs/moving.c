/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 20:46:19 by jericard          #+#    #+#             */
/*   Updated: 2026/02/11 20:46:20 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	compatible_rotate(int *stack_a, int *stack_b, int *tops, int tail)
{
	int	valor_a;
	int	valor_b;
	int	bc;

	bc = best_costs(stack_a, stack_b, tops, tail);
	valor_a = stack_a[bc];
	valor_b = stack_b[fnd_target_a(stack_a[bc], stack_b, tops[1], tail)];
	while (valor_a != stack_a[tops[0]] && valor_b != stack_b[tops[1]])
		rr(stack_a, stack_b, tops, tail);
	while (valor_a != stack_a[tops[0]])
		ra(stack_a, tops[0], tail, 0);
	while (valor_b != stack_b[tops[1]])
		rb(stack_b, tops[1], tail, 0);
}

static void	compatible_reverse(int *stack_a, int *stack_b, int *tops, int tail)
{
	int	valor_a;
	int	valor_b;
	int	bc;

	bc = best_costs(stack_a, stack_b, tops, tail);
	valor_a = stack_a[bc];
	valor_b = stack_b[fnd_target_a(stack_a[bc], stack_b, tops[1], tail)];
	while (valor_a != stack_a[tops[0]] && valor_b != stack_b[tops[1]])
		rrr(stack_a, stack_b, tops, tail);
	while (valor_a != stack_a[tops[0]])
		rra(stack_a, tops[0], tail, 0);
	while (valor_b != stack_b[tops[1]])
		rrb(stack_b, tops[1], tail, 0);
}

static void	compatible_non(int *stack_a, int *stack_b, int *tops, int tail)
{
	int	valor_a;
	int	valor_b;
	int	target;
	int	bc;

	bc = best_costs(stack_a, stack_b, tops, tail);
	target = fnd_target_a(stack_a[bc], stack_b, tops[1], tail);
	valor_a = stack_a[bc];
	valor_b = stack_b[target];
	if (bc <= magic(tail, tops[0], 2))
		while (valor_a != stack_a[tops[0]])
			ra(stack_a, tops[0], tail, 0);
	else
		while (valor_a != stack_a[tops[0]])
			rra(stack_a, tops[0], tail, 0);
	if (target <= magic(tail, tops[1], 2))
		while (valor_b != stack_b[tops[1]])
			rb(stack_b, tops[1], tail, 0);
	else
		while (valor_b != stack_b[tops[1]])
			rrb(stack_b, tops[1], tail, 0);
}

void	manager(int *stack_a, int *stack_b, int *tops, int tail)
{
	int	best_point;
	int	target;
	int	line_a;
	int	line_b;

	line_a = magic(tail, tops[0], 2);
	line_b = magic(tail, tops[1], 2);
	best_point = best_costs(stack_a, stack_b, tops, tail);
	target = fnd_target_a(stack_a[best_point], stack_b, tops[1], tail);
	if (target == tops[1] && best_point == (tops[0] + 1))
		sa(stack_a, tops[0], tail + 1, 0);
	else if (best_point <= line_a && target <= line_b)
		compatible_rotate(stack_a, stack_b, tops, tail);
	else if (best_point > line_a && target > line_b)
		compatible_reverse(stack_a, stack_b, tops, tail);
	else
		compatible_non(stack_a, stack_b, tops, tail);
	pb(stack_a, &tops[0], stack_b, &tops[1]);
}
