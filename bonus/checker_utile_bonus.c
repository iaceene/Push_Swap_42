/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utile_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:47:47 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/26 12:13:11 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	instruction_app(char *buffer, t_list **stack_a, t_list **stack_b)
{
	if (ft_strcmp(buffer, "sa\n") == 0)
		ft_swap_stack(stack_a);
	else if (ft_strcmp(buffer, "sb\n") == 0)
		ft_swap_stack(stack_b);
	else if (ft_strcmp(buffer, "ss\n") == 0)
		ft_swap_all(stack_a, stack_b);
	else if (ft_strcmp(buffer, "pa\n") == 0)
		ft_push(stack_b, stack_a);
	else if (ft_strcmp(buffer, "pb\n") == 0)
		ft_push(stack_a, stack_b);
	else if (ft_strcmp(buffer, "ra\n") == 0)
		ft_rotate(stack_a);
	else if (ft_strcmp(buffer, "rb\n") == 0)
		ft_rotate(stack_b);
	else if (ft_strcmp(buffer, "rr\n") == 0)
		ft_rotate_all(stack_a, stack_b);
	else if (ft_strcmp(buffer, "rra\n") == 0)
		ft_reverse_rotate(stack_a);
	else if (ft_strcmp(buffer, "rrb\n") == 0)
		ft_reverse_rotate(stack_b);
	else if (ft_strcmp(buffer, "rrr\n") == 0)
		ft_reverse_all(stack_a, stack_b);
	else
		return (1);
	return (0);
}

int	ft_exe_ens(t_command *head, t_list **stack_a, t_list **stack_b)
{
	while (head)
	{
		instruction_app(head->cmd, stack_a, stack_b);
		head = head->next;
	}
	return (0);
}

t_command	*ft_new_cmd(char *buffer)
{
	t_command	*new;

	new = malloc(sizeof(t_command));
	if (!new)
		return (NULL);
	new->cmd = ft_strdup(buffer);
	if (!new->cmd)
		return (NULL);
	new->next = NULL;
	return (new);
}

t_command	*ft_lstlast_cmd(t_command *head)
{
	if (!head)
		return (NULL);
	while (head && head->next)
		head = head->next;
	return (head);
}

int	ft_addback_cmd(t_command **head, t_command *new)
{
	t_command	*last_node;

	if (!head || !new)
		return (1);
	if (!*head)
		*head = new;
	else
	{
		last_node = ft_lstlast_cmd(*head);
		last_node->next = new;
	}
	return (0);
}
