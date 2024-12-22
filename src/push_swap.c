/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:23:57 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/22 15:58:14 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_three(t_list **stack_a)
{
	int	max_index;

	rank_stack(*stack_a);
	max_index = get_index(stack_a, ft_lstsize(stack_a) - 1);
	if (max_index == 0)
		ft_rotate(stack_a, 1);
	if (max_index == 1)
		ft_reverse_rotate(stack_a, 1);
	if ((*stack_a)->data > (*stack_a)->next->data)
		ft_swap_stack(stack_a, 1);
	return (0);
}

int	ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_a || !stack_a)
		return (1);
	while (ft_lstsize(stack_a) > 3)
		ft_push_min(stack_a, stack_b);
	ft_sort_three(stack_a);
	while (ft_lstsize(stack_b) > 0)
		ft_push(stack_b, stack_a, 1);
	return (0);
}

int	ft_push_swap(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(stack_a);
	if (!stack_a || !*stack_a)
		return (1);
	if (size == 2)
		ft_swap_stack (stack_a, 1);
	else if (size == 3)
		return (ft_sort_three(stack_a));
	else if (size >= 4 && size < 6)
		return (ft_sort_five(stack_a, stack_b));
	else
		return (push_to_b(stack_a, stack_b), push_to_a(stack_a, stack_b), 0);
	return (0);
}
