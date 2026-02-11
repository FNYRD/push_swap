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

void none(int *stack_a, int *stack_b, int *tops, int tail)
{
    int best_point;
	int	target;
	int	line_a;
	int	line_b;
	int	flag;

	flag = 0;
	line_a = magic(tail, tops[0], 2);
	line_b = magic(tail, tops[1], 2);
	target = fnd_target_a(stack_a[best_cost], stack_b, tops[1], tail);
    best_point = best_costs(stack_a, stack_b, tops, tail);
	if (stack_a[best_cost] == line_a || stack_b[target] == line_b)
	{
		if (!(stack_a[best_point] == line_a))
		{
			if (stack_a[best_point] > line_a)
				flag = 1;
			if (flag == 1)
			{
				
			}
		}
	}

}