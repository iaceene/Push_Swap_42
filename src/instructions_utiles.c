/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utiles.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:06:17 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/16 11:12:47 by yaajagro         ###   ########.fr       */
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
	ft_swap_stack(stack_a);
	ft_swap_stack(stack_b);
}

void	ft_rotate_all(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}

void	ft_reverse_all(t_list **stack_a, t_list **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
}
