/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utiles.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:06:17 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/18 10:22:25 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_node(t_list **node)
{
	if (node && *node)
	{
		free(*node);
		*node = NULL;
	}
}

void	ft_swap_all(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !stack_b || !*stack_a || !*stack_b)
		return ;
	ft_swap_stack(stack_a, 1);
	ft_swap_stack(stack_b, 2);
}

void	ft_rotate_all(t_list **stack_a, t_list **stack_b)
{
	if (stack_a && *stack_a)
		ft_rotate(stack_a, 1);
	if (stack_b && *stack_b)
		ft_rotate(stack_b, 2);
}

void	ft_reverse_all(t_list **stack_a, t_list **stack_b)
{
	if (stack_a && *stack_a)
		ft_reverse_rotate(stack_a, 1);
	if (stack_b && *stack_b)
		ft_reverse_rotate(stack_b, 2);
}

int	ft_sort_checker(t_list **list)
{
	t_list	*tmp;

	if (!list || !*list)
		return (0);
	tmp = *list;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
