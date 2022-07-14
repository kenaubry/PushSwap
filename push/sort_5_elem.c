/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <kenaubry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 23:23:49 by kenaubry          #+#    #+#             */
/*   Updated: 2022/07/13 23:23:52 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_pile	*find_first_5(t_stacks *stacks, t_pile *head, int *index, int i)
{
	t_pile	*littlest;
	t_pile	*stack_a;
	int		nb;

	stack_a = stacks->stack_a;
	nb = stack_a->data;
	while (stack_a->next != NULL)
	{
		if (stack_a->data <= nb)
		{
			nb = stack_a->data;
			littlest = stack_a;
			*index = i;
		}
		i++;
		stack_a = stack_a->next;
	}
	if (stack_a->next == NULL && stack_a->data < nb)
	{
		*index = i;
		nb = stack_a->data;
		littlest = stack_a;
	}
	return (head);
}

static t_pile	*first_5(t_stacks *stacks, t_pile *head)
{
	t_pile	*stack_a;
	t_pile	*littlest;
	int		index;
	int		i;
	int		nb;

	index = 0;
	i = 0;
	stack_a = stacks->stack_a;
	nb = stack_a->data;
	find_first_5(stacks, head, &index, i);
	if (index == 0 || index == 1)
		index_zero_one(stacks, head, index);
	else if (index == 2 || index == 3)
		index_two_three(stacks, head, index);
	else
		index_last(stacks, head);
	return (head);
}

static t_pile	*find_second_5(t_stacks	*stacks, t_pile *head, int *id, int i)
{
	t_pile	*stack_a;
	t_pile	*littlest;
	int		nb;

	stack_a = stacks->stack_a;
	nb = stack_a->data;
	while (stack_a->next != NULL)
	{
		if (stack_a->data <= nb)
		{
			nb = stack_a->data;
			littlest = stack_a;
			*id = i;
		}
		i++;
		stack_a = stack_a->next;
	}
	if (stack_a->next == NULL && stack_a->data < nb)
	{
		*id = i;
		nb = stack_a->data;
		littlest = stack_a;
	}
	return (head);
}

static t_pile	*second_5(t_stacks *stacks, t_pile *head)
{
	t_pile	*littlest;
	t_pile	*stack_a;
	int		index;
	int		i;
	int		nb;

	i = 0;
	index = 0;
	stack_a = stacks->stack_a;
	nb = stack_a->data;
	find_second_5(stacks, head, &index, i);
	if (index == 0 || index == 1)
		index_zo_second(stacks, head, index);
	else
		index_last_second(stacks, head, index);
	return (head);
}

void	ft_sort_5_elem(t_stacks *stacks)
{
	t_pile	*stack_a;
	t_pile	*littlest;
	t_pile	*head;
	int		index;
	int		i;

	index = 0;
	i = 0;
	first_5(stacks, head);
	second_5(stacks, head);
	ft_sort_3_elem(stacks);
	head = stacks->stack_b->next;
	stacks->stack_a = push_stack(&stacks->stack_a, &stacks->stack_b);
	stacks->stack_b = head;
	instructions(&stacks->inst, 3);
	head = stacks->stack_b->next;
	stacks->stack_a = push_stack(&stacks->stack_a, &stacks->stack_b);
	stacks->stack_b = head;
	instructions(&stacks->inst, 3);
}
