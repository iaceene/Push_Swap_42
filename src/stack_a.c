#include "push_swap.h"

int stack_init(char *str, t_list *stack)
{
    char	**numbers;
    int     N;
    int     i;

    N = ft_count(str, ' ');
    i = 0;
    numbers = ft_split(str, ' ');
    if (!numbers)
        return (1);
    while (i < N)
    {
        if(ft_overflow(numbers[i]))
            return (1);
        printf("%ld\n", ft_atol(numbers[i]));
        i++;
    }
    return (0);
}