#include "push_swap.h"

void    ra(int *stack_a, int *top_a, int tail, int flag)
{
    int temp;
    int i;

    temp = stack_a[*top_a];
    i = *top_a;
    while (i < tail)
    {
        stack_a[i] = stack_a[i + 1];
        i++;
    }
    stack_a[tail] = temp;
    if (!flag)
        ft_printf("ra\n");
}

void    rb(int *stack_b, int *top_b, int tail, int flag)
{
    ra(stack_b, top_b, tail, 0);
    if (!flag)
        ft_printf("rb\n");
}

void rr(int  *stack_a, int *top_a, int *stack_b, int *top_b, int tail)
{
    ra(stack_a, top_a, tail, 1);
    rb(stack_b, top_b, tail, 1);
    ft_printf("rr\n");
}
