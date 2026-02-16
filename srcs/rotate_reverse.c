/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:25:23 by jericard          #+#    #+#             */
/*   Updated: 2026/02/09 16:25:25 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(int *stack_a, int top_a, int tail, int flag)
{
	int	temp;
	int	i;

	temp = stack_a[tail];
	i = tail;
	while (i >= top_a)
	{
		stack_a[i + 1] = stack_a[i];
		i--;
	}
	stack_a[top_a] = temp;
	if (!flag)
		ft_printf("rra\n");
}

void	rrb(int *stack_b, int top_b, int tail, int flag)
{
	rra(stack_b, top_b, tail, 1);
	if (!flag)
		ft_printf("rrb\n");
}

void	rrr(int *stack_a, int *stack_b, int *tops, int tail)
{
	rra(stack_a, tops[0], tail, 1);
	rra(stack_b, tops[1], tail, 1);
	ft_printf("rrr\n");
}
