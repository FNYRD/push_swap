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
		return(((a + 1) - b) / 2 + b);
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

// tengo que disminuir una linea de la funcion
int	best_costs(int *stack_a, int *stack_b, int *tops, int tail)
{
	int	target;
	int	point;
	int	total;
	int	best_cost;
	int	best_point;

	best_cost = INT_MAX;
	best_point = tops[0];
	point = tops[0] - 1;
	total = -1;
	while (++point <= tail)
	{
		target = fnd_target_a(stack_a[point], stack_b, tops[1], tail);
		if (move(point, target, magic(tail, tops[0], 2), magic(tail, tops[1], 2)))
			total = magic(mvs(point, tops[0], tail), mvs(target, tops[1], tail), 1);
		else
			total = mvs(point, tops[0], tail) + mvs(target, tops[1], tail);
		if (total < best_cost)
		{
			best_point = point;
			best_cost = total;
		}
	}
	return (best_point);
}

// encontrar target de b
 	// target = fnd_target_b(stack_b[tops[1]], stack_a, tops[0], tail);

 	// i = 0;
	// while (i++ < 2)
	// 	pb(stack_a, &tops[0],  stack_b, &tops[1]);
	// print_test(stack_a, &tops[0], stack_b, &tops[1], tail, tail + 1);

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

// static void    print_test(int *stack_a, int *top_a,  int *stack_b, int *top_b, int tail, int len)
// {
// 	(void)len;
// 	ft_printf("Antes\n");
// 	// int i = 0;
// 	// int	n = 0;
// 	print_helper(stack_a,top_a, tail, stack_b, top_b);
// 	// n = 9;
// 	// ft_printf("Push %d numeros de a para b\n", n);

// 	// while (i++ < n)
// 	// 	pb(stack_a, top_a,  stack_b, top_b);

// 	// print_helper(stack_a,top_a, tail, stack_b, top_b);
// }