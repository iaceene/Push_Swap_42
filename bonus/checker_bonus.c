/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:23:57 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/17 09:56:36 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "get_next_line_bonus.h"



int instruction_valid(char *buffer, t_list **stack_a, t_list **stack_b)
{
    if (strnstr(buffer, "sa", ft_strlen(buffer)))
        ft_swap_stack(stack_a);
    else if (strnstr(buffer, "sb", ft_strlen(buffer)))
        ft_swap_stack(stack_b);
    else if (strnstr(buffer, "ss", ft_strlen(buffer)))
        ft_swap_all(stack_a, stack_b);
    else if (strnstr(buffer, "pa", ft_strlen(buffer)))
        ft_push(stack_a, stack_b);
    else if (strnstr(buffer, "pb", ft_strlen(buffer)))
        ft_push(stack_b, stack_a);
    else if (strnstr(buffer, "ra", ft_strlen(buffer)))
        ft_rotate(stack_a);
    else if (strnstr(buffer, "rb", ft_strlen(buffer)))
        ft_rotate(stack_b);
    else if (strnstr(buffer, "rr", ft_strlen(buffer)))
        ft_rotate_all(stack_a, stack_b);
    else if (strnstr(buffer, "rra", ft_strlen(buffer)))
        ft_reverse_rotate(stack_a);
    else if (strnstr(buffer, "rrb", ft_strlen(buffer)))
        ft_reverse_rotate(stack_b);
    else if (strnstr(buffer, "rrr", ft_strlen(buffer)))
        ft_reverse_all(stack_a, stack_b);
    else
        return (0);
    return (1);
}

int ft_instructions(t_list **stack_a, t_list **stack_b)
{
    char *buffer;

    buffer = get_next_line(0);
    while(buffer)
    {
        if(instruction_valid(buffer, stack_a, stack_b))
            continue ;
        else
            return (1);
        free(buffer);
        buffer = get_next_line(0);
    }
    return (0);
}