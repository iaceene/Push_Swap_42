/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:31:13 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/22 16:01:22 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rank_stack(t_list *stack)
{
	t_list	*f;

	f = stack;
	while (stack)
	{
		stack->rank = get_count(&f, stack->data);
		stack = stack->next;
	}
}

int	get_index(t_list **stack, int rank)
{
	int		count;
	t_list	*tmp;

	count = 0;
	tmp = *stack;
	while (tmp)
	{
		if (tmp -> rank == rank)
			return (count);
		count++;
		tmp = tmp -> next;
	}
	return (-1);
}

int	get_count(t_list **stack, int num)
{
	int		count;
	t_list	*tmp;

	tmp = *stack;
	count = 0;
	while (tmp)
	{
		if (tmp->data < num)
			count++;
		tmp = tmp ->next;
	}
	return (count);
}

void	ft_push_min(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	index;

	rank_stack(*stack_a);
	index = get_index(stack_a, 0);
	size = ft_lstsize(stack_a);
	if (index < size / 2 && (*stack_a)->rank != 0)
		while ((*stack_a)->rank != 0)
			ft_rotate(stack_a, 1);
	else
		while ((*stack_a)->rank != 0)
			ft_reverse_rotate(stack_a, 1);
	ft_push(stack_a, stack_b, 2);
}
