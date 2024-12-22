/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_above_utiles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:14:17 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/22 15:10:46 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rank_stack(t_list *stack)
{
	t_list	*f;

	f = stack;
	while (stack)
	{
		stack->rank = get_count(f, stack->data);
		stack = stack->next;
	}
}
