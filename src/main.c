/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 02:59:04 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/18 18:45:13 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_mult_check(char **v, int c)
{
	int	i;

	i = 0;
	while (i < c)
	{
		if (!ft_check(v[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_init(int c, char **v, t_list **stack_a)
{
	int	check_err;

	check_err = 0;
	if (c == 1)
		return (1);
	else if (c == 2 && ft_check(v[1]))
		check_err += stack_init(v[1], stack_a, 0);
	else if (c >= 3 && ft_mult_check(v + 1, c - 1))
		check_err += stack_init_mult(v + 1, stack_a);
	else
		check_err++;
	if (check_err == 0)
	{
		if (ft_stack_checker(stack_a) == 1)
			return (1);
	}
	return (check_err);
}

void	vk(void)
{
	system("leaks checker");
}

int	main(int c, char **v)
{
	int		check_err;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (c == 1)
		return (0);
	check_err = ft_init(c, v, &stack_a);
	if (check_err > 0)
		return (print_err("Error\n"), ft_lstclear(&stack_a), 1);
	else if (ft_sort_checker(&stack_a) == 1 || ft_lstsize(&stack_a) == 1)
		return (ft_lstclear(&stack_a), ft_lstclear(&stack_b), 0);
	
	check_err += ft_push_swap(&stack_a, &stack_b);
	return (ft_lstclear(&stack_a), ft_lstclear(&stack_b), check_err);
}
