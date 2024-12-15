/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 03:02:45 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/15 10:23:54 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	if(!s1 && !s2)
		return (NULL);
	else if(!s1 && s2)
		return(ft_strdup(s2));
	else if(!s2 && s1)
		return (ft_strdup(s1));
	char *final;
	final = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if(!final)
		return (NULL);
	int i = 0;
	int index = 0;
	while(s1[i])
		final[index++] = s1[i++];
	final[index++] = ' ';
	i = 0;
	while(s2[i])
		final[index++] = s2[i++];
	final[index] = '\0';
	return (final);
}

int stack_init_mult(char **v, t_list **stack)
{
	char	*final;
	int		err;
	int		i;
	char 	*tmp;

	err = 0;
	i = 0;
	final = NULL;
	while(v[i])
	{
		tmp = final;
		final = ft_strjoin(final, v[i]);
		if(!final)
			return (1);
		free(tmp);
		i++;
	}
	err += stack_init(final, stack, 1);
	return (err);
}


int	stack_init(char *str, t_list **stack, int args)
{
	char	**numbers;
	int		i;
	int		err_check;

	i = 0;
	err_check = 0;
	printf("%s \n", str);
	numbers = ft_split(str, ' ');
	if (!numbers)
	{
		if(args == 1)
			return (free(str), 1);
		else
			return (1);
	}
	if(args == 1)
		free(str);
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
