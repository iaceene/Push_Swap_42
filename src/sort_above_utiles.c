/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_above_utiles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:14:17 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/21 20:24:22 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_it(t_list *stack)
{
	t_list	*f;
	int		index;

	index = 0;
	f = stack;
	while (stack)
	{
		stack->rank = get_count(f, stack->data);
		stack->index = index++;
		stack = stack->next;
	}
}
