/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <kenaubry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:03:58 by kenaubry          #+#    #+#             */
/*   Updated: 2022/07/06 17:04:13 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_median(t_pile **stacks, int pile, int n)
{
	t_pile	*tmp;
	int		i;
	int		*tab;
	int		len;
	int		median;

	i = 0;
	len = n;
	tab = (int *)malloc(sizeof(int) * (len + 1));
	if (!tab)
		exit(1);
	tmp = *stacks;
	while (i < len)
	{
		tab[i++] = tmp->data;
		tmp = tmp->next;
	}
	ft_sort_tab(tab, len);
	if (pile == 2 && len % 2 == 0)
		median = tab[(len / 2) - 1];
	else
		median = tab[(len / 2)];
	free(tab);
	return (median);
}

int	ft_compare_with_median(t_stacks *stacks, int n, int median, int stack)
{
	int		i;
	t_pile	*elem;

	i = 0;
	if (stack == 1)
		elem = stacks->stack_a;
	else if (stack == 2)
		elem = stacks->stack_b;
	while (i < n)
	{
		if (stack == 1 && elem->data < median)
			return (1);
		if (stack == 2 && elem->data > median)
			return (1);
		i++;
		elem = elem->next;
	}
	return (0);
}
