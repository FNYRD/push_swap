/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:00:00 by jericard          #+#    #+#             */
/*   Updated: 2026/02/16 18:00:00 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	read_line(char *buf, int size)
{
	int		i;
	int		ret;
	char	c;

	i = 0;
	while (i < size - 1)
	{
		ret = read(0, &c, 1);
		if (ret <= 0)
			return (-1);
		if (c == '\n')
			break ;
		buf[i++] = c;
	}
	buf[i] = '\0';
	return (i);
}

int	is_sorted_chk(int *stack, int top, int tail)
{
	while (top < tail)
	{
		if (stack[top] > stack[top + 1])
			return (0);
		top++;
	}
	return (1);
}

static int	exec_swap(char *op, int *a, int *b, int *tops)
{
	int	tail;

	tail = tops[2];
	if (ft_strncmp(op, "ss", 3) == 0)
	{
		sa(a, tops[0], tail + 1, 1);
		sb(b, tops[1], tail + 1, 1);
	}
	else if (ft_strncmp(op, "sa", 3) == 0)
		sa(a, tops[0], tail + 1, 1);
	else if (ft_strncmp(op, "sb", 3) == 0)
		sb(b, tops[1], tail + 1, 1);
	else
		return (0);
	return (1);
}

static int	exec_rot(char *op, int *a, int *b, int *tops)
{
	int	tail;

	tail = tops[2];
	if (ft_strncmp(op, "rrr", 4) == 0)
	{
		rra(a, tops[0], tail, 1);
		rra(b, tops[1], tail, 1);
	}
	else if (ft_strncmp(op, "rra", 4) == 0)
		rra(a, tops[0], tail, 1);
	else if (ft_strncmp(op, "rrb", 4) == 0)
		rrb(b, tops[1], tail, 1);
	else if (ft_strncmp(op, "rr", 3) == 0)
	{
		ra(a, tops[0], tail, 1);
		ra(b, tops[1], tail, 1);
	}
	else if (ft_strncmp(op, "ra", 3) == 0)
		ra(a, tops[0], tail, 1);
	else if (ft_strncmp(op, "rb", 3) == 0)
		rb(b, tops[1], tail, 1);
	else
		return (0);
	return (1);
}

int	exec_op(char *op, int *a, int *b, int *tops)
{
	int	tail;

	tail = tops[2];
	if (exec_swap(op, a, b, tops))
		return (1);
	if (exec_rot(op, a, b, tops))
		return (1);
	if (ft_strncmp(op, "pa", 3) == 0 && tops[1] <= tail)
	{
		tops[0]--;
		a[tops[0]] = b[tops[1]];
		tops[1]++;
	}
	else if (ft_strncmp(op, "pb", 3) == 0 && tops[0] <= tail)
	{
		tops[1]--;
		b[tops[1]] = a[tops[0]];
		tops[0]++;
	}
	else
		return (0);
	return (1);
}
