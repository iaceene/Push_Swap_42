/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 02:59:04 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/16 11:14:36 by yaajagro         ###   ########.fr       */
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

void	ft_print_list(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	printf("stack : ");
	while (tmp)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
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
	check_err += ft_stack_checker(stack_a);
	if (check_err >= 1)
		ft_putstr("Error\n");
	return (check_err);
}

void	f(void)
{
	system("leaks a.out");
}

int	main(int c, char **v)
{
	t_list	*stack_a;
	int		check_err;

	atexit(f);
	stack_a = NULL;
	check_err = ft_init(c, v, &stack_a);
	if (check_err > 0)
		return (ft_lstclear(&stack_a), 1);
	ft_print_list(stack_a);
	ft_lstclear(&stack_a);
	return (0);
}
