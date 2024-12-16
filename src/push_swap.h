/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 03:04:11 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/16 11:14:28 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <libc.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

int		is_space(char c);
int		is_number(char c);
int		valid_sing(char *s, int index);
void	ft_putstr(char *s);
char	*ft_strdup(char *s);
int		ft_strlen(char *s);
int		ft_stack_checker(t_list **stack_a);
int		ft_check(char *s);
char	**ft_split(char const *s, char c);
char	**ft_free(char **splites, int index);
int		ft_count(char *str, char spliter);
int		stack_init(char *str, t_list **stack, int args);
int		stack_init_mult(char **v, t_list **stack_a);
long	ft_atol(char *s);
int		ft_overflow(char *s);
t_list	*ft_lstlast(t_list *head);
t_list	*ft_addnew(int data);
int		ft_addback(t_list **head, t_list *new);
void	ft_lstclear(t_list **lst);
void	ft_free_node(t_list **node);
/// instrutions functions
void	ft_swap_stack(t_list **stack);
void	ft_swap_all(t_list **stack_a, t_list **stack_b);
void	ft_push(t_list **stack_a, t_list **stack_b);
void	ft_rotate(t_list **stack);
void	ft_rotate_all(t_list **stack_a, t_list **stack_b);
void	ft_reverse_rotate(t_list **stack);
void	ft_reverse_all(t_list **stack_a, t_list **stack_b);
#endif