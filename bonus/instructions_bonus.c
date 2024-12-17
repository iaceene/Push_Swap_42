/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:05:12 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/17 08:54:37 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_swap_stack(t_list **stack)
{
	t_list	*tmp;
	t_list	*netmp;

	if (!stack || !*stack)
		return ;
	netmp = (*stack)->next->next;
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->next = tmp;
	tmp->next = netmp;
}

void	ft_push(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_a || !*stack_a || !stack_b)
		return ;
	if (!*stack_b)
	{
		*stack_b = ft_addnew((*stack_a)->data);
		if (!*stack_b)
			return ;
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		ft_free_node(&tmp);
	}
	else
	{
		tmp = *stack_b;
		*stack_b = ft_addnew((*stack_a)->data);
		if (!*stack_b)
			return ;
		(*stack_b)->next = tmp;
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		ft_free_node(&tmp);
	}
}

void	ft_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*lst;

	if (!stack || !*stack)
		return ;
	tmp = *stack;
	lst = ft_lstlast(*stack);
	*stack = (*stack)->next;
	lst->next = tmp;
	tmp->next = NULL;
}

void	ft_reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*cur;

	if (!stack || !*stack)
		return ;
	last = *stack;
	cur = NULL;
	while (last->next)
	{
		cur = last;
		last = last->next;
	}
	cur->next = NULL;
	last->next = *stack;
	*stack = last;
}
