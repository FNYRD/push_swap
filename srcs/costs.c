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

void    none(int *stack_a, int *stack_b, int *tops, int tail)
{
    int line_a;
    int line_b;
    int location;
    int target;
    int cost;

    location = tops[0];
    line_a = ((tail + 1) - tops[0]) / 2 +  tops[0];
    line_b = ((tail + 1) - tops[1]) / 2 +  tops[1];
    while (location <= tail)
    {
        target = fnd_target_a(stack_a[location], stack_b, tops[1], tail);
        if (target == tops[1])
            cost = 0; //caso ya esta en el top
        else if (target == tops[1] + 1) //caso sea swap
            cost = 1;
        else if 
        location++;
    }
    ft_printf("line_a: %d\n", stack_a[line_a]);
    ft_printf("line_b: %d\n", stack_b[line_b]);
    //Line se recibe mandando len - *top / 2 + top. Esto da el indice correcto
    //target es el indice del target
    // if target <= line
}
