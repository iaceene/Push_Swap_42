/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:31:13 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/21 20:33:15 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index(t_list **stack)
{
	int		max;
	int		i;
	int		index;
	t_list	*tmp;

	if (!*stack || !stack)
		return (-1);
	tmp = *stack;
	max = 0;
	i = 0;
	index = 0;
	while (tmp)
	{
		if (tmp->data > max)
		{
			max = tmp->data;
			index = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (index);
}

int	find_min_index(t_list **stack)
{
	int		min;
	int		i;
	int		index;
	t_list	*tmp;

	if (!*stack || !stack)
		return (-1);
	tmp = *stack;
	min = tmp->data;
	i = 0;
	index = 0;
	while (tmp)
	{
		if (tmp->data < min)
		{
			min = tmp->data;
			index = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (index);
}

int	find_min(t_list **stack)
{
	t_list	*tmp;
	int		min;

	tmp = *stack;
	min = tmp->data;
	while (tmp)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}

void	ft_push_min(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	index;
	int	min;

	min = find_min(stack_a);
	index = find_min_index(stack_a);
	size = ft_lstsize(stack_a);
	if (index < size / 2 && (*stack_a)->data != min)
		while ((*stack_a)->data != min)
			ft_rotate(stack_a, 1);
	else
		while ((*stack_a)->data != min)
			ft_reverse_rotate(stack_a, 1);
	ft_push(stack_a, stack_b, 2);
}
