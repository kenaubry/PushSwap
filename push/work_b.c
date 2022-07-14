/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <kenaubry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:04:58 by kenaubry          #+#    #+#             */
/*   Updated: 2022/07/06 17:05:00 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_median_sort(t_stacks *stacks, int len, int *r, int *p)
{
	int		i;
	int		median;
	t_pile	*tmp;

	i = 0;
	median = ft_median(&stacks->stack_b, 2, len);
	while (ft_compare_with_median(stacks, len - i, median, 2) && i++ < len)
	{
		if (stacks->stack_b->data > median)
		{
			tmp = stacks->stack_b->next;
			stacks->stack_a = push_stack(&stacks->stack_a, &stacks->stack_b);
			stacks->stack_b = tmp;
			instructions(&stacks->inst, 3);
			*p = *p + 1;
		}
		else
		{
			stacks->stack_b = rotate_stack(&stacks->stack_b);
			instructions(&stacks->inst, 6);
			*r = *r + 1;
		}
	}
}

static void	ft_place(t_stacks *stacks, int *r)
{
	int	lenb;

	lenb = size_stack(&stacks->stack_b);
	if (*r > (lenb / 2) && lenb > 3)
	{
		while (*r < lenb)
		{
			stacks->stack_b = rotate_stack(&stacks->stack_b);
			instructions(&stacks->inst, 6);
			*r = *r + 1;
		}
	}
	else if (lenb > 3)
	{
		while (*r)
		{
			stacks->stack_b = reverse_rotate_stack(&stacks->stack_b);
			instructions(&stacks->inst, 8);
			*r = *r - 1;
		}
	}
}

void	ft_work_b(t_stacks *stacks, int len)
{
	int		r;
	int		p;
	t_pile	*tmp;

	r = 0;
	p = 0;
	if (len <= 3)
	{
		ft_sort_min_b(stacks);
		return ;
	}
	ft_median_sort(stacks, len, &r, &p);
	ft_work_a(stacks, p);
	ft_place(stacks, &r);
	ft_work_b(stacks, len - p);
	if (stacks->stack_b != NULL && is_stack_sort(&stacks->stack_b, 2) == 1)
	{
		while (p--)
		{
			tmp = stacks->stack_a->next;
			stacks->stack_b = push_stack(&stacks->stack_b, &stacks->stack_a);
			stacks->stack_a = tmp;
			instructions(&stacks->inst, 4);
		}
	}
}
