#include "push_swap.h"

void    pa(int  *stack_a, int *top_a, int *stack_b, int *top_b)
{
    if (*top_b < 0)
        return ;
    (*top_a)--;
    stack_a[*top_a] = stack_b[*top_b];
    (*top_b)++;
    ft_printf("pa\n");
}

void    pb(int  *stack_a, int *top_a, int *stack_b, int *top_b)
{
    if (*top_a < 0)
        return ;
    (*top_b)--;
    stack_b[*top_b] = stack_a[*top_a];
    (*top_a)++;
    ft_printf("pb\n");
}