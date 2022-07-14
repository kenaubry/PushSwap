/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <kenaubry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:04:25 by kenaubry          #+#    #+#             */
/*   Updated: 2022/07/06 17:04:28 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_2_elem(t_stacks *stacks)
{
	t_pile	*elem;

	elem = stacks->stack_a;
	if (elem->data > elem->next->data)
	{
		stacks->stack_a = swap_stack(&stacks->stack_a);
		instructions(&stacks->inst, 1);
	}
}

static void	ft_rot(t_pile **e, t_pile **s, t_stacks *stacks)
{
	t_pile	*elem;
	t_pile	*suiv;

	elem = *e;
	suiv = *s;
	if (elem->data < suiv->data)
	{
		if (elem->data < suiv->next->data)
		{
			stacks->stack_a = reverse_rotate_stack(&stacks->stack_a);
			instructions(&stacks->inst, 7);
		}
		else
		{
			stacks->stack_a = rotate_stack(&stacks->stack_a);
			instructions(&stacks->inst, 5);
		}
	}
}

void	ft_sort_3_elem(t_stacks *stacks)
{
	t_pile	*elem;
	t_pile	*suiv;

	while (stacks->stack_a != NULL && is_stack_sort(&stacks->stack_a, 1) != 0)
	{
		elem = stacks->stack_a;
		suiv = elem->next;
		if (elem->data > suiv->data)
		{
			if (elem->data < suiv->next->data)
			{
				stacks->stack_a = swap_stack(&stacks->stack_a);
				instructions(&stacks->inst, 1);
			}
			else
			{
				stacks->stack_a = rotate_stack(&stacks->stack_a);
				instructions(&stacks->inst, 5);
			}
		}
		else if (stacks->stack_a != NULL \
			&& is_stack_sort(&stacks->stack_a, 1) != 0)
			ft_rot(&elem, &suiv, stacks);
	}
}

void	ft_sort_min_a(t_stacks *stacks)
{
	int	len;

	len = size_stack(&stacks->stack_a);
	if (len > 1 && stacks->stack_a->data > stacks->stack_a->next->data)
	{
		stacks->stack_a = swap_stack(&stacks->stack_a);
		instructions(&stacks->inst, 1);
	}
	if (len > 2 \
		&& stacks->stack_a->next->data > stacks->stack_a->next->next->data)
	{
		stacks->stack_a = rotate_stack(&stacks->stack_a);
		stacks->stack_a = swap_stack(&stacks->stack_a);
		stacks->stack_a = reverse_rotate_stack(&stacks->stack_a);
		instructions(&stacks->inst, 5);
		instructions(&stacks->inst, 1);
		instructions(&stacks->inst, 7);
	}
	if (len > 1 && stacks->stack_a->data > stacks->stack_a->next->data)
	{
		stacks->stack_a = swap_stack(&stacks->stack_a);
		instructions(&stacks->inst, 1);
	}
}

void	ft_sort_min_b(t_stacks *stacks)
{
	int	len;

	len = size_stack(&stacks->stack_b);
	if (len > 1 && stacks->stack_b->data < stacks->stack_b->next->data)
	{
		stacks->stack_b = swap_stack(&stacks->stack_b);
		instructions(&stacks->inst, 2);
	}
	if (len > 2 \
		&& stacks->stack_b->next->data < stacks->stack_b->next->next->data)
	{
		stacks->stack_b = rotate_stack(&stacks->stack_b);
		stacks->stack_b = swap_stack(&stacks->stack_b);
		stacks->stack_b = reverse_rotate_stack(&stacks->stack_b);
		instructions(&stacks->inst, 6);
		instructions(&stacks->inst, 2);
		instructions(&stacks->inst, 8);
	}
	if (len > 1 && stacks->stack_b->data < stacks->stack_b->next->data)
	{
		stacks->stack_b = swap_stack(&stacks->stack_b);
		instructions(&stacks->inst, 2);
	}
}
