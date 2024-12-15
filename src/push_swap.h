#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H


#include "libc.h"

typedef struct s_list
{
	int			    data;
    int             pos;
	struct s_list	*next;
}	t_list;

int is_space(char c);
int is_number(char c);
int valid_sing(char *s, int index);
void ft_putstr(char *s);
int ft_check(char *s);
char	**ft_split(char const *s, char c);
int	ft_count(char *str, char spliter);
int stack_init(char *str, t_list *stack);
long ft_atol(char *s);

#endif

