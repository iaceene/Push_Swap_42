/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 05:39:43 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/17 19:11:45 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (!lst || !(*lst))
		return ;
	while ((*lst))
	{
		tmp = (*lst)->next;
		free((*lst));
		(*lst) = tmp;
	}
}

int	ft_lstsize(t_list **lst)
{
	t_list	*tmp;
	int		size;

	if (!lst || !*lst)
		return (0);
	size = 0;
	tmp = *lst;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

int	stack_b_checker(t_list **stack_b)
{
	if (ft_lstsize(stack_b) > 0)
		return (0);
	return (1);
}
