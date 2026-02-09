/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_and_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:24:57 by jericard          #+#    #+#             */
/*   Updated: 2026/02/09 16:24:58 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_int_array(int *new_array)
{
	if (!new_array)
		return ;
	free(new_array);
	new_array = NULL;
}

void	free_matriz(char **matriz)
{
	int	i;

	i = 0;
	if (!matriz)
		return ;
	while (matriz[i])
	{
		free(matriz[i]);
		i++;
	}
	free(matriz);
}

void	ft_exit(char **matriz)
{
	if (matriz)
		free_matriz(matriz);
	write(2, "Error\n", 6);
	exit(1);
}
