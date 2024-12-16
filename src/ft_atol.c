/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 03:01:58 by yaajagro          #+#    #+#             */
/*   Updated: 2024/12/16 11:24:19 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *s)
{
	int		i;
	int		sing;
	long	res;

	if (!s)
		return (0);
	i = 0;
	res = 0;
	sing = 1;
	while (is_space(s[i]))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sing = -1;
		i++;
	}
	while (is_number(s[i]))
	{
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	return (res * sing);
}
