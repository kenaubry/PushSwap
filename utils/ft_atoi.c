/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <[kenaubry@student.42.fr]>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:28:06 by kenaubry          #+#    #+#             */
/*   Updated: 2021/09/12 16:28:07 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_error(t_stacks *stacks, char *s, int *tab)
{
	write(2, "Error\n", 6);
	free(s);
	free(tab);
	free_all(stacks);
	exit(1);
}

int	ft_atoi(const char *str, t_stacks *stacks, int *tab)
{
	int					i;
	int					k;
	unsigned long long	n;

	i = 0;
	n = 0;
	k = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i++] == 45)
			k = -1;
	}
	if (i == (int)ft_strlen(str))
		ft_error(stacks, (char *)str, tab);
	while (str[i] > 47 && str[i] < 58)
	{
		n = 10 * n + (str[i++] - 48);
		if ((n > 2147483647 && k == 1) || (n > 2147483648 && k == -1))
			ft_error(stacks, (char *)str, tab);

	}
	if (i == 0 || i != (int)ft_strlen(str))
		ft_error(stacks, (char *)str, tab);
	return ((int)n * k);
}
