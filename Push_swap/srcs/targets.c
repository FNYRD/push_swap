#include "push_swap.h"

int    fnd_target_a(int a, int *b, int tb, int tail)
{
    int dif;
    int index;
    index = -1;
    dif = INT_MAX;
    while(tb <= tail)
    {
        if (a > b[tb] && (a - b[tb]) < dif)
            index = tb;
        tb++;
    }
    if (index == -1)
        return (set_i(b, tb, tail, 1));
    return (index);
}