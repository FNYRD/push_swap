/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:34:28 by jericard          #+#    #+#             */
/*   Updated: 2026/02/18 15:34:29 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(int *stack_a, int top_a, int len, int flag)
{
	int	temp;

	if ((len - top_a) <= 1)
		return ;
	temp = stack_a[top_a];
	stack_a[top_a] = stack_a[top_a + 1];
	stack_a[top_a + 1] = temp;
	if (!flag)
		ft_printf("sa\n");
}

void	sb(int *stack_b, int top_b, int len, int flag)
{
	int	temp;

	if ((len - top_b) <= 1)
		return ;
	temp = stack_b[top_b];
	stack_b[top_b] = stack_b[top_b + 1];
	stack_b[top_b + 1] = temp;
	if (!flag)
		ft_printf("sb\n");
}

void	ss(int *stack_a, int len, int *stack_b, int *tops)
{
	sa(stack_a, tops[0], len, 1);
	sb(stack_b, tops[1], len, 1);
	ft_printf("ss\n");
}
