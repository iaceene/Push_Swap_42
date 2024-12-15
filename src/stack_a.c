/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 03:02:45 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/15 03:03:40 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_init(char *str, t_list *stack)
{
	char	**numbers;
	int		i;

	i = 0;
	numbers = ft_split(str, ' ');
	if (!numbers)
		return (1);
	while (numbers[i])
	{
		if (ft_overflow(numbers[i]))
			return (1);
		printf("%ld\n", ft_atol(numbers[i]));
		i++;
	}
	return (0);
}
