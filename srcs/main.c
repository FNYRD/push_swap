/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:23:06 by jericard          #+#    #+#             */
/*   Updated: 2026/02/09 16:23:08 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	*twoargs(char **matriz, int len)
{
	int		*new_array;

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

static	int	*moreargs(char **argv, int len)
{
	int		*new_array;

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
		new_array = twoargs(matriz, len);
	}
	else if (argc > 2)
	{
		len = matriz_len(argv, 1);
		new_array = moreargs(argv, len);
	}
	if (!new_array)
		ft_exit(NULL);
	else
		processor(new_array, len);
	return (0);
}
// int		i;//BORRAR
// i = -1;//BORRAR
// while (++i < matriz_len(argv, 1))//BORRAR
// 	printf("\n%d", new_array[i]);//BORRAR
