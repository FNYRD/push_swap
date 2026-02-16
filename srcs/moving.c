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



// static	void	print_helper(int *stack_a, int *top_a, int tail, int *stack_b, int *top_b)
// {
// 	int topf;
// 	int topf2;
// 	int i;

// 	i = 0;
// 	topf = *top_a;
// 	topf2 = *top_b;
// 	ft_printf("\n");
// 	while (i <= tail)
// 	{
// 		if(topf <= tail)
// 			ft_printf("%d", stack_a[topf]);
// 		else
// 			ft_printf(" "); 
// 		ft_printf("   ");  
// 		if (topf2 <= tail)
// 			ft_printf("%d", stack_b[topf2]);
// 		ft_printf("\n"); 
// 		topf++;
// 		topf2++;
// 		i++;
// 	}
// 	ft_printf("\n");
// }

void static mockup(int *stack_a, int *stack_b, int *tops, int tail)
{
    int best_point;
	int	target;
	int	line_a;
	int	line_b;
	int	valor_a;
	int	valor_b;

	valor_a = 0;
	valor_b = 0;
	line_a = magic(tail, tops[0], 2);
	line_b = magic(tail, tops[1], 2);
    best_point = best_costs(stack_a, stack_b, tops, tail);
	target = fnd_target_a(stack_a[best_point], stack_b, tops[1], tail);
	valor_a = stack_a[best_point];
	valor_b = stack_b[target];
	// si el target de A esta en top+1 solo necesita swap
	if (target == tops[1] && best_point == (tops[0] + 1))
		sa(stack_a, tops[0], tail + 1, 0);
	// caso sean combinables y se puedan mover ambos y luego mover solo el falta
	else if (move(best_point, target, line_a, line_b))
	{
		if (best_point <= line_a || target <= line_b)
		{
			while (valor_a != stack_a[tops[0]] && valor_b != stack_b[tops[1]])
				rr(stack_a, stack_b, tops, tail);
			while (valor_a != stack_a[tops[0]])
				ra(stack_a, tops[0], tail, 0);
			while (valor_b != stack_b[tops[1]])
				rb(stack_b, tops[1], tail, 0);
		}
		else
		{
			while (valor_a != stack_a[tops[0]] && valor_b != stack_b[tops[1]])
				rrr(stack_a, stack_b, tops, tail);
			while (valor_a != stack_a[tops[0]])
				rra(stack_a, tops[0], tail, 0);
			while (valor_b != stack_b[tops[1]])
				rrb(stack_b, tops[1], tail, 0);			
		}
	}
	// no sean combinables y tenga que moverlos en direcciones diferentes 
	else
	{
		if (best_point <= line_a)
		{
			while (valor_a != stack_a[tops[0]])
				ra(stack_a, tops[0], tail, 0);
		}
		else
		{
			while (valor_a != stack_a[tops[0]])
				rra(stack_a, tops[0], tail, 0);
		}
		if (target <= line_b)
		{
			while (valor_b != stack_b[tops[1]])
				rb(stack_b, tops[1], tail, 0);
		}
		else
		{
			while (valor_b != stack_b[tops[1]])
				rrb(stack_b, tops[1], tail, 0);
		}
	}
	// si ambos esta en el top 
	pb(stack_a, &tops[0],stack_b, &tops[1]);
}

void none(int *stack_a, int *stack_b, int *tops, int tail)
{
	int line_b;
	int	greater;
	int	n;

	line_b = magic(tail, tops[1], 2);
	while (((tail + 1) - tops[0]) > 3)
	{
		mockup(stack_a, stack_b, tops, tail);
		// print_helper(stack_a, &tops[0], tail, stack_b, &tops[1]);
	}
	greater = set_i(stack_b, tops[1], tail, 1);
	n = stack_b[greater];
	if(stack_b[greater] <= stack_b[line_b])
	{
		while (n != stack_b[tops[1]])
			rb(stack_b, tops[1], tail, 0);
	}
	else
	{
		while (n != stack_b[tops[1]])
			rrb(stack_b, tops[1], tail, 0);		
	}
	// print_helper(stack_a, &tops[0], tail, stack_b, &tops[1]);
}