/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_above.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:46:40 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/21 20:24:09 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_helper(t_list **stack_a, t_list **stack_b, int i, int j)
{
	while (*stack_a)
	{
		if (i >= (*stack_a)->rank)
		{
			ft_push(stack_a, stack_b, 2);
			i++;
		}
		else if (i + j > (*stack_a)->rank)
		{
			ft_push(stack_a, stack_b, 2);
			ft_rotate(stack_b, 2);
			i++;
		}
		else
			ft_rotate(stack_a, 1);
	}
}

void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	size;
	int	j;

	i = 0;
	size = ft_lstsize(stack_a);
	if (size > 120)
		j = size / 15;
	else
		j = size / 7;
	push_b_helper(stack_a, stack_b, i, j);
}

int	get_index(t_list *stack, int rank)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (stack -> rank == rank)
			return (count);
		count++;
		stack = stack -> next;
	}
	return (-1);
}

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	int	size;

	index_it(*stack_b);
	while (*stack_b)
	{
		size = ft_lstsize(stack_b);
		if (get_index(*stack_b, size - 1) > size / 2)
		{
			while ((*stack_b)->rank != size - 1)
				ft_reverse_rotate(stack_b, 2);
		}
		else
		{
			while ((*stack_b)->rank != size - 1)
				ft_rotate(stack_b, 2);
		}
		ft_push(stack_b, stack_a, 1);
	}
}

int	get_count(t_list *lst, int num)
{
	int	count;

	count = 0;
	while (lst)
	{
		if (lst->data < num)
			count++;
		lst = lst ->next;
	}
	return (count);
}
