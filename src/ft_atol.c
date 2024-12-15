#include "push_swap.h"

long ft_atol(char *s)
{
    int i;
    int sing;
    long res;

    i = 0;
    res = 0;
    sing = 1;
    while(is_space(s[i]))
        i++;
    if(s[i] == '+' || s[i] == '-')
    {
        if(s[i] == '-')
            sing = -1;
        i++;
    }
    while(is_number(s[i]))
    {
        res = (res * 10) + (s[i] - '0');
        i++;
    }
    return (res * sing);
}
