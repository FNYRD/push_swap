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

static	int	*duplicating(int len)
{
	int	*array_duplicated;

	array_duplicated = ft_calloc(len, sizeof(int));
	if (!array_duplicated)
		return (NULL);
	return (array_duplicated);
}

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

void	order_3(int *stack_a, int min, int max)
{
	int	top_a;

	top_a = 0;
	if (max == 1 && min == 0)
	{
		sa(stack_a, top_a, 3, 0);
		ra(stack_a, top_a, 2, 0);
	}
	else if (max == 0 && min == 1)
		ra(stack_a, top_a, 2, 0);
	else if (max == 2 && min == 1)
		sa(stack_a, top_a, 3, 0);
	else if (max == 1 && min == 2)
		rra(stack_a, top_a, 2, 0);
	else if (max == 0 && min == 2)
	{
		sa(stack_a, top_a, 3, 0);
		rra(stack_a, top_a, 2, 0);
	}
}

void	processor(int *stack_a, int len)
{
	int	*stack_b;
	//BORRAR
	int	top_a;
	int	top_b;
	//BORRAR
	stack_b = duplicating(len);
	if (!stack_b)
	{
		free_int_array(stack_a);
		ft_exit(NULL);
	}
	if (len == 3)
		order_3(stack_a, set_i(stack_a, 0, 2, 0), set_i(stack_a, 0, 2, 1));
	//BORRAR
	top_a = 0;//REFERENCIA
	top_b = len;//REFERENCIA
	int tops[] = {top_a, top_b};
	none(stack_a, stack_b, tops, len - 1);
	//BORRAR
}

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

// static void    print_test(int  *stack_a, int *top_a,  int *stack_b, int *top_b, int tail, int len)
// {
// 	(void)len;
// 	ft_printf("%d\n", tail);
// 	ft_printf("Antes\n");
// 	int i = 0;
// 	print_helper(stack_a,top_a, tail, stack_b, top_b);
// 	ft_printf("Push 3 numero de a para b\n");
// 	while (i++ < 9)
// 		pb(stack_a, top_a,  stack_b, top_b);
// 	print_helper(stack_a,top_a, tail, stack_b, top_b);
// 	ft_printf("target A: %d\n", stack_b[(fnd_target_a(stack_a[*top_a], stack_b, *top_b, tail))]);
// 	ft_printf("target B: %d\n", stack_a[fnd_target_b(stack_b[*top_b], stack_a, *top_a, tail)]);
// 	int tops[] = {*top_a, *top_b};
// 	none(stack_a, stack_b, tops, tail);
// }