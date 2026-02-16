/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:00:00 by jericard          #+#    #+#             */
/*   Updated: 2026/02/16 18:00:00 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		exec_op(char *op, int *a, int *b, int *tops);
int		read_line(char *buf, int size);
int		is_sorted_chk(int *stack, int top, int tail);

static void	checker_error(int *a, int *b)
{
	free(a);
	free(b);
	write(2, "Error\n", 6);
	exit(1);
}

static void	run_checker(int *a, int len)
{
	int		*b;
	int		tops[3];
	char	buf[5];

	b = ft_calloc(len, sizeof(int));
	if (!b)
	{
		free(a);
		ft_exit(NULL);
	}
	tops[0] = 0;
	tops[1] = len;
	tops[2] = len - 1;
	while (read_line(buf, 5) >= 0)
	{
		if (!exec_op(buf, a, b, tops))
			checker_error(a, b);
	}
	if (is_sorted_chk(a, tops[0], tops[2]) && tops[1] > tops[2])
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(a);
	free(b);
}

static int	*parse_two(char **matriz, int len)
{
	int	*new_array;

	error(matriz, 0);
	new_array = parsed_array(matriz, 0);
	if (!new_array)
		ft_exit(matriz);
	if (!(non_duplicate(new_array, len)))
	{
		free_int_array(new_array);
		ft_exit(matriz);
	}
	free_matriz(matriz);
	return (new_array);
}

static int	*parse_more(char **argv, int len)
{
	int	*new_array;

	error(argv, 1);
	new_array = parsed_array(argv, 1);
	if (!new_array)
		ft_exit(NULL);
	if (!(non_duplicate(new_array, len)))
	{
		free_int_array(new_array);
		ft_exit(NULL);
	}
	return (new_array);
}

int	main(int argc, char **argv)
{
	char	**matriz;
	int		*new_array;
	int		len;

	new_array = NULL;
	if (argc == 2)
	{
		matriz = ft_split(argv[1], ' ');
		if (!matriz)
			ft_exit(NULL);
		len = matriz_len(matriz, 0);
		new_array = parse_two(matriz, len);
	}
	else if (argc > 2)
	{
		len = matriz_len(argv, 1);
		new_array = parse_more(argv, len);
	}
	if (!new_array)
		return (0);
	run_checker(new_array, len);
	return (0);
}
