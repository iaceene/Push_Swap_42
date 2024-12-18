/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:23:57 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/18 13:05:59 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

int	find_max_index(t_list **stack)
{
	int		max;
	int		i;
	int		index;
	t_list	*tmp;
	
	if(!*stack || !stack)
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

int	ft_sort_three(t_list **stack_a)
{
	int max_index;

	max_index = find_max_index(stack_a);
	if (max_index == 0)
		ft_rotate(stack_a, 1);
	if (max_index == 1)
		ft_reverse_rotate(stack_a, 1);
	if ((*stack_a)->data > (*stack_a)->next->data)
		ft_swap_stack(stack_a, 1);
	return (0);
}

int ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	t_list **min;

	// ft_push()
	// 2056+63
}

int	ft_push_swap(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_a || !stack_a)
		return (1);
	if (ft_lstsize(stack_a) == 2)
		ft_swap_stack (stack_a, 1);
	else if (ft_lstsize(stack_a) == 3)
		return (ft_sort_three(stack_a));
	else if (ft_lstsize(stack_a) == 5)
		return (ft_sort_five(stack_a, stack_b));
	if (!*stack_b)
		return (0);
	return (0);
}
