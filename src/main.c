#include "libc.h"

int is_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\r');
}

int is_number(char c)
{
    return (c >= '0' && c <= '9');
}

int valid_sing(char *s, int index)
{
    if(s[index] != '+' && s[index] != '-')
        return (0);
    else if((s[index] == '+' && !is_number(s[index + 1]))
           || (s[index] == '-' && !is_number(s[index + 1])))
        return (0);
    return (1);
}

int ft_check(char *s)
{
    int i = 0;
    if(s[i] == '\0')
        return (0);
    while(s[i])
    {
        if(!is_number(s[i]) && !is_space(s[i]) && !valid_sing(s, i))
            return (0);
        i++;
    }
    return (1);
}

int main(int c, char **v)
{
    if (c == 1)
        return (1);
    else if (c == 2 && ft_check(v[1]))
    {
        printf("valid\n");
    }
    else
        printf("Error\n");
    return (0);
}