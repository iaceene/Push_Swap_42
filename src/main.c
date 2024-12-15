/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 02:59:04 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/15 10:30:51 by yaajagro         ###   ########.fr       */
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
// check_err += stack_init_mult(v + 1, c - 1, stack_a);
void 	ft_print_list(t_list *stack)
{
	t_list *tmp = stack;
	while(tmp)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}

void	f()
{
	system("leaks a.out");
}

int	main(int c, char **v)
{
	atexit(f);
	t_list	*stack_a;
	int		check_err;

	stack_a = NULL;
	check_err = 0;
	if (c == 1)
		return (1);
	else if (c == 2 && ft_check(v[1]))
		check_err += stack_init(v[1], &stack_a, 0);
	else if (c >= 3 && ft_mult_check(v + 1, c - 1))
		check_err += stack_init_mult(v + 1, &stack_a);
	else
		ft_putstr("Error\n");
	if (check_err >= 1)
		ft_putstr("Error\n");
	ft_print_list(stack_a);
	ft_lstclear(&stack_a);
	return (0);
}
