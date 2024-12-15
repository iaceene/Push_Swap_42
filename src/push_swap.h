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
int ft_overflow(char *s);
int ft_strlen(char *s);
t_list	*ft_lstlast(t_list *head);
int ft_addback(t_list **head, t_list *new);
t_list *ft_addnew(int data);

#endif

