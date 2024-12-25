/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:23:57 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/25 20:49:07 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "push_swap_bonus.h"

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

int is_valid(char *buffer) {
	
	
	
	char *cmd[] = {
        "sa\n", "sb\n", "ss\n", "pa\n", "pb\n", 
        "ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"
    };

	int i = 0;
    while (i < 11) 
	{
        if (ft_strcmp(buffer, cmd[i]) == 0)
            return 0;
		i++;
    }
    return 1;
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
			return (free(buffer), 1);
		free(buffer);
		buffer = get_next_line(0);
	}
	return (ft_exe_ens(head, stack_a, stack_b));
}
