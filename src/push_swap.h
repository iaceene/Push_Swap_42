/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 03:04:11 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/22 16:03:22 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				data;
	int				rank;
	struct s_list	*next;
}	t_list;

int		is_space(char c);
int		is_number(char c);
int		valid_sing(char *s, int index);
void	ft_putstr(char *s);
void	print_err(char *s);
char	*ft_strdup(char *s);
int		ft_strlen(char *s);
int		ft_stack_checker(t_list **stack_a);
int		ft_check(char *s);
char	**ft_split(char const *s, char c);
char	**ft_free(char **splites, int index);
int		ft_count(char *str, char spliter);
int		stack_init(char *str, t_list **stack, int args);
int		stack_init_mult(char **v, t_list **stack_a);
int		ft_sort_checker(t_list **list);
long	ft_atol(char *s);
int		ft_overflow(char *s);
t_list	*ft_lstlast(t_list *head);
t_list	*ft_addnew(int data);
int		ft_addback(t_list **head, t_list *new);
void	ft_lstclear(t_list **lst);
void	ft_free_node(t_list **node);
int		stack_b_checker(t_list **stack_b);
int		ft_lstsize(t_list **lst);
/// instrutions functions
void	ft_swap_stack(t_list **stack, int c);
void	ft_swap_all(t_list **stack_a, t_list **stack_b);
void	ft_push(t_list **stack_a, t_list **stack_b, int c);
void	ft_rotate(t_list **stack, int c);
void	ft_rotate_all(t_list **stack_a, t_list **stack_b);
void	ft_reverse_rotate(t_list **stack, int c);
void	ft_reverse_all(t_list **stack_a, t_list **stack_b);
// logic
int		ft_push_swap(t_list **stack_a, t_list **stack_b);
void	ft_push_min(t_list **stack_a, t_list **stack_b);
// sort 100 && 500
void	push_to_b(t_list **stack_a, t_list **stack_b);
int		get_index(t_list **stack, int rank);
void	push_to_a(t_list **stack_a, t_list **stack_b);
int		get_count(t_list **stack, int num);
void	rank_stack(t_list **stack);

#endif