/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:23:57 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/17 10:30:14 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "get_next_line_bonus.h"



int instruction_valid(char *buffer, t_list **stack_a, t_list **stack_b)
{
    if (strncmp(buffer, "sa", ft_strlen(buffer) - 1) == 0)
        ft_swap_stack(stack_a);
    else if (strncmp(buffer, "sb", ft_strlen(buffer) - 1) == 0)
        ft_swap_stack(stack_b);
    else if (strncmp(buffer, "ss", ft_strlen(buffer) - 1) == 0)
        ft_swap_all(stack_a, stack_b);
    else if (strncmp(buffer, "pa", ft_strlen(buffer) - 1) == 0)
        ft_push(stack_b, stack_a);
    else if (strncmp(buffer, "pb", ft_strlen(buffer) - 1) == 0)
        ft_push(stack_a, stack_b);
    else if (strncmp(buffer, "ra", ft_strlen(buffer) - 1) == 0)
        ft_rotate(stack_a);
    else if (strncmp(buffer, "rb", ft_strlen(buffer) - 1) == 0)
        ft_rotate(stack_b);
    else if (strncmp(buffer, "rr", ft_strlen(buffer) - 1) == 0)
        ft_rotate_all(stack_a, stack_b);
    else if (strncmp(buffer, "rra", ft_strlen(buffer) - 1) == 0)
        ft_reverse_rotate(stack_a);
    else if (strncmp(buffer, "rrb", ft_strlen(buffer) - 1) == 0)
        ft_reverse_rotate(stack_b);
    else if (strncmp(buffer, "rrr", ft_strlen(buffer) - 1) == 0)
        ft_reverse_all(stack_a, stack_b);
    else
        return (1);
    return (0);
}

int ft_instructions(t_list **stack_a, t_list **stack_b)
{
    char *buffer;
    int err = 0;

    buffer = get_next_line(0);
    while(buffer)
    {
        err = instruction_valid(buffer, stack_a, stack_b);
        if(err == 1)
            return (free(buffer), 1);
        free(buffer);
        buffer = get_next_line(0);
    }
    return (0);
}