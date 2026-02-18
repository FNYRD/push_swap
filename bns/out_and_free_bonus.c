/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_and_free_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:33:43 by jericard          #+#    #+#             */
/*   Updated: 2026/02/18 15:33:44 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
