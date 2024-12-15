#include "push_swap.h"

int ft_strlen(char *s)
{
    int i = 0;
    while(s[i])
        i++;
    return(i);
}

int ft_buffer(char *s)
{
    int len = ft_strlen(s);
    if(len >= ft_strlen("18446744073709551616"))
        return (1);
    return (0);
}

int ft_overflow(char *s)
{
    long n = ft_atol(s);
    if (n > INT_MAX || n < INT_MIN || ft_buffer(s))
        return 1;
    return 0;
}