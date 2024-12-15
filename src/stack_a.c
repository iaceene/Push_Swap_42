/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 03:02:45 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/15 04:49:46 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_init(char *str, t_list **stack)
{
	char	**numbers;
	int		i;
	int		err_check;

	i = 0;
	err_check = 0;
	numbers = ft_split(str, ' ');
	if (!numbers)
		return (1);
	while (numbers[i])
	{
		if (ft_overflow(numbers[i]) || err_check > 0)
			return (ft_lstclear(stack), 1);
		err_check += ft_addback(stack, ft_addnew(ft_atol(numbers[i])));
		i++;
	}
	ft_free(numbers, i);
	return (0);
}
