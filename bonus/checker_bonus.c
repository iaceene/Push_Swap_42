/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:23:57 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/26 12:10:09 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "push_swap_bonus.h"

void	ft_lstcmdclear(t_command **head)
{
	t_command	*tmp;

	if (!head || !(*head))
		return ;
	while ((*head))
	{
		tmp = (*head)->next;
		free((*head)->cmd);
		free((*head));
		(*head) = tmp;
	}
	*head = NULL;
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

int	is_valid(char *buffer)
{
	if (ft_strcmp(buffer, "sa\n") == 0)
		return (0);
	else if (ft_strcmp(buffer, "sb\n") == 0)
		return (0);
	else if (ft_strcmp(buffer, "ss\n") == 0)
		return (0);
	else if (ft_strcmp(buffer, "pa\n") == 0)
		return (0);
	else if (ft_strcmp(buffer, "pb\n") == 0)
		return (0);
	else if (ft_strcmp(buffer, "ra\n") == 0)
		return (0);
	else if (ft_strcmp(buffer, "rb\n") == 0)
		return (0);
	else if (ft_strcmp(buffer, "rr\n") == 0)
		return (0);
	else if (ft_strcmp(buffer, "rra\n") == 0)
		return (0);
	else if (ft_strcmp(buffer, "rrb\n") == 0)
		return (0);
	else if (ft_strcmp(buffer, "rrr\n") == 0)
		return (0);
	else
		return (1);
	return (1);
}

int	ft_instructions(t_list **stack_a, t_list **stack_b)
{
	char		*buffer;
	int			err;
	t_command	*head;

	err = 0;
	buffer = get_next_line(0);
	head = NULL;
	while (buffer)
	{
		if (buffer[0] == '\n')
			return (free(buffer), 1);
		err = is_valid(buffer);
		err += ft_addback_cmd(&head, ft_new_cmd(buffer));
		if (err == 1)
			return (free(buffer), ft_lstcmdclear(&head), 1);
		free(buffer);
		buffer = get_next_line(0);
	}
	return (ft_exe_ens(head, stack_a, stack_b), ft_lstcmdclear(&head), 0);
}
