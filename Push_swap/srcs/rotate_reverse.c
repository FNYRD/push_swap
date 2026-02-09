#include "push_swap.h"

void    rra(int *stack_a, int *top_a, int tail, int flag)
{
    int temp;
    int i;

    temp = stack_a[tail];
    i = tail;
    while (i >= *top_a)
    {
        stack_a[i + 1] = stack_a[i];
        i--;
    }
    stack_a[*top_a] = temp;
    if (!flag)
        ft_printf("rra\n");
}

void    rrb(int *stack_b, int *top_b, int tail, int flag)
{
    rra(stack_b, top_b, tail, 0);
    if (!flag)
        ft_printf("rra\n");
}

void    rrr(int  *stack_a, int *top_a, int *stack_b, int *top_b, int tail)
{
    rra(stack_a, top_a, tail, 1);
    rra(stack_b, top_b, tail, 1);
    ft_printf("rrr\n");
}