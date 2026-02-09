/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:25:14 by jericard          #+#    #+#             */
/*   Updated: 2026/02/09 16:25:16 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../ft_printf/includes/ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		matriz_len(char **matriz, int index);
int		non_duplicate(int *new_array, int len);
int		*parsed_array(char **matriz, int index);
int		fnd_target_a(int a, int *b, int tb, int tail);
int     fnd_target_b(int b, int *a, int ta, int tail);
int		set_i(int *stack, int top, int tail, int flag);

void	ft_exit(char **matriz);
void	free_matriz(char **matriz);
void	error(char **matriz, int mi);
void	free_int_array(int *new_array);
void	processor(int *stack_a, int len);
void	order_3(int *stack_a, int min, int max);

void	sa(int *stack_a, int top, int len, int flag);
void	sb(int *stack_b, int top_b, int len, int flag);
void	ss(int *stack_a, int len, int *stack_b, int *tops);

void	ra(int *stack_a, int top_a, int tail, int flag);
void	rb(int *stack_b, int top_b, int tail, int flag);
void	rr(int *stack_a, int *stack_b, int *tops, int tail);

void	rra(int *stack_a, int top_a, int tail, int flag);
void	rrb(int *stack_b, int top_b, int tail, int flag);
void	rrr(int *stack_a, int *stack_b, int *tops, int tail);

void	pa(int *stack_a, int *top_a, int *stack_b, int *top_b);
void	pb(int *stack_a, int *top_a, int *stack_b, int *top_b);


void    none(int *stack_a, int *stack_b, int *tops, int tail);

#endif
