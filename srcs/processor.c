/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:25:05 by jericard          #+#    #+#             */
/*   Updated: 2026/02/09 16:25:06 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_i(int *stack, int top, int tail, int flag)
{
	int	i;
	int	index;

	index = top;
	i = top + 1;
	while (i <= tail)
	{
		if (flag == 0 && stack[i] < stack[index])
			index = i;
		else if (flag == 1 && stack[i] > stack[index])
			index = i;
		i++;
	}
	return (index);
}

void	order_3(int *stack_a, int top_a)
{
	int	max;
	int	min;
	int	t;

	t = top_a;
	min = set_i(stack_a, t, t + 2, 0);
	max = set_i(stack_a, t, t + 2, 1);
	if (max == t + 1 && min == t)
	{
		sa(stack_a, t, t + 3, 0);
		ra(stack_a, t, t + 2, 0);
	}
	else if (max == t && min == t + 1)
		ra(stack_a, t, t + 2, 0);
	else if (max == t + 2 && min == t + 1)
		sa(stack_a, t, t + 3, 0);
	else if (max == t + 1 && min == t + 2)
		rra(stack_a, t, t + 2, 0);
	else if (max == t && min == t + 2)
	{
		sa(stack_a, t, t + 3, 0);
		rra(stack_a, t, t + 2, 0);
	}
}

static int	is_sorted(int *stack, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	small_sort(int *stack_a, int *stack_b, int len)
{
	if (len == 2)
		sa(stack_a, 0, 2, 0);
	else if (len == 3)
		order_3(stack_a, 0);
	free(stack_a);
	if (stack_b)
		free(stack_b);
}

void	processor(int *stack_a, int len)
{
	int	*stack_b;
	int	tops[2];

	if (len <= 1 || is_sorted(stack_a, len))
	{
		free(stack_a);
		return ;
	}
	stack_b = ft_calloc(len, sizeof(int));
	if (!stack_b)
	{
		free_int_array(stack_a);
		ft_exit(NULL);
	}
	if (len <= 3)
	{
		small_sort(stack_a, stack_b, len);
		return ;
	}
	tops[0] = 0;
	tops[1] = len;
	director(stack_a, stack_b, tops, len - 1);
}
