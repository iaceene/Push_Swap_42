/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:23:57 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/17 11:33:51 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "get_next_line_bonus.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		if (str1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

int	instruction_valid(char *buffer, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(buffer, "sa", ft_strlen(buffer) - 1) == 0)
		ft_swap_stack(stack_a);
	else if (ft_strncmp(buffer, "sb", ft_strlen(buffer) - 1) == 0)
		ft_swap_stack(stack_b);
	else if (ft_strncmp(buffer, "ss", ft_strlen(buffer) - 1) == 0)
		ft_swap_all(stack_a, stack_b);
	else if (ft_strncmp(buffer, "pa", ft_strlen(buffer) - 1) == 0)
		ft_push(stack_b, stack_a);
	else if (ft_strncmp(buffer, "pb", ft_strlen(buffer) - 1) == 0)
		ft_push(stack_a, stack_b);
	else if (ft_strncmp(buffer, "ra", ft_strlen(buffer) - 1) == 0)
		ft_rotate(stack_a);
	else if (ft_strncmp(buffer, "rb", ft_strlen(buffer) - 1) == 0)
		ft_rotate(stack_b);
	else if (ft_strncmp(buffer, "rr", ft_strlen(buffer) - 1) == 0)
		ft_rotate_all(stack_a, stack_b);
	else if (ft_strncmp(buffer, "rra", ft_strlen(buffer) - 1) == 0)
		ft_reverse_rotate(stack_a);
	else if (ft_strncmp(buffer, "rrb", ft_strlen(buffer) - 1) == 0)
		ft_reverse_rotate(stack_b);
	else if (ft_strncmp(buffer, "rrr", ft_strlen(buffer) - 1) == 0)
		ft_reverse_all(stack_a, stack_b);
	else
		return (1);
	return (0);
}

int	ft_instructions(t_list **stack_a, t_list **stack_b)
{
	char	*buffer;
	int		err;

	err = 0;
	buffer = get_next_line(0);
	while (buffer)
	{
		if (buffer[0] == '\n')
			return (free(buffer), 1);
		err = instruction_valid(buffer, stack_a, stack_b);
		if (err == 1)
			return (free(buffer), 1);
		free(buffer);
		buffer = get_next_line(0);
	}
	return (0);
}
