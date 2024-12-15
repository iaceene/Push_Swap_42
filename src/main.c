#include "push_swap.h"

int ft_mult_check(char **v, int c)
{
    int i = 0;
    while(i < c)
    {
        if(!ft_check(v[i]))
            return (0);
        i++;
    }
    return (1);
}

int main(int c, char **v)
{
    t_list *stack_a;
    int     check_err;

    stack_a = NULL;
    check_err = 0;
    if (c == 1)
        return (1);
    else if (c == 2 && ft_check(v[1]))
        check_err += stack_init(v[1], stack_a);
    else if (c >= 3 && ft_mult_check(v + 1, c - 1))
        printf("hi");// check_err += stack_init_mult(v + 1, c - 1, stack_a);
    else
        ft_putstr("Error\n");
    if(check_err >= 1)
        ft_putstr("Error\n");
    return (0);
}
