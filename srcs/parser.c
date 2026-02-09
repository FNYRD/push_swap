/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:23:34 by jericard          #+#    #+#             */
/*   Updated: 2026/02/09 16:23:35 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atoi_modified(const char *nptr)
{
	long	i;
	long	ret;
	long	signal;

	i = 0;
	ret = 0;
	signal = 1;
	while (nptr[i] == 32 || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			signal *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		ret = ret * 10 + (nptr[i] - '0');
		i++;
	}
	return ((ret * signal));
}

static void	less_lines(char **matriz, int *new_array, int is_argv)
{
	free_int_array(new_array);
	if (is_argv)
		ft_exit(NULL);
	else
		ft_exit(matriz);
}

int	*parsed_array(char **matriz, int index)
{
	int		*new_array;
	int		len;
	int		i;
	long	test;
	int		is_argv;

	is_argv = (index == 1);
	len = matriz_len(matriz, index);
	new_array = ft_calloc(len, sizeof(int));
	if (!new_array)
		return (NULL);
	i = 0;
	test = 0;
	while (matriz[index] && (i < len))
	{
		test = ft_atoi_modified(matriz[index++]);
		if (test > INT_MAX || test < INT_MIN)
			less_lines(matriz, new_array, is_argv);
		new_array[i] = (int)test;
		i++;
	}
	return (new_array);
}
