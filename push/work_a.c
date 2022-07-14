/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <kenaubry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:04:53 by kenaubry          #+#    #+#             */
/*   Updated: 2022/07/06 17:04:54 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_median_sort(t_stacks *stacks, int len, int *r, int *p)
{
	int		i;
	int		median;
	t_pile	*tmp;

	i = 0;
	median = ft_median(&stacks->stack_a, 1, len);
	while (ft_compare_with_median(stacks, len - i, median, 1) && i++ < len)
	{
		if (stacks->stack_a->data < median)
		{
			tmp = stacks->stack_a->next;
			stacks->stack_b = push_stack(&stacks->stack_b, &stacks->stack_a);
			stacks->stack_a = tmp;
			instructions(&stacks->inst, 4);
			*p = *p + 1;
		}
		else
		{
			stacks->stack_a = rotate_stack(&stacks->stack_a);
			instructions(&stacks->inst, 5);
			*r = *r + 1;
		}
	}
}

static void	ft_place(t_stacks *stacks, int *r)
{
	int	lena;

	lena = size_stack(&stacks->stack_a);
	if (*r > (lena / 2) && lena > 3)
	{
		while (*r < lena)
		{
			stacks->stack_a = rotate_stack(&stacks->stack_a);
			instructions(&stacks->inst, 5);
			*r = *r + 1;
		}
	}
	else if (lena > 3)
	{
		while (*r)
		{
			stacks->stack_a = reverse_rotate_stack(&stacks->stack_a);
			instructions(&stacks->inst, 7);
			*r = *r - 1;
		}
	}
}

void	ft_work_a(t_stacks *stacks, int len)
{
	int		r;
	int		p;
	t_pile	*tmp;

	r = 0;
	p = 0;
	if (len <= 3)
	{
		ft_sort_min_a(stacks);
		return ;
	}
	if (stacks->stack_a != NULL && is_stack_sort(&stacks->stack_a, 1) == 0)
		return ;
	ft_median_sort(stacks, len, &r, &p);
	ft_place(stacks, &r);
	ft_work_a(stacks, (len - p));
	ft_work_b(stacks, p);
	while (p-- && stacks->stack_b != NULL)
	{
		tmp = stacks->stack_b->next;
		stacks->stack_a = push_stack(&stacks->stack_a, &stacks->stack_b);
		stacks->stack_b = tmp;
		instructions(&stacks->inst, 3);
	}
}
