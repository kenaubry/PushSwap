/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <kenaubry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 00:20:58 by kenaubry          #+#    #+#             */
/*   Updated: 2022/07/14 00:21:01 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_pile	*index_zero_one(t_stacks *stacks, t_pile *head, int index )
{
	if (index == 0)
	{
		head = stacks->stack_a->next;
		stacks->stack_b = push_stack(&stacks->stack_b, &stacks->stack_a);
		stacks->stack_a = head;
		instructions(&stacks->inst, 4);
	}
	else
	{
		stacks->stack_a = swap_stack(&stacks->stack_a);
		head = stacks->stack_a->next;
		instructions(&stacks->inst, 1);
		stacks->stack_b = push_stack(&stacks->stack_b, &stacks->stack_a);
		stacks->stack_a = head;
		instructions(&stacks->inst, 4);
	}
	return (head);
}

t_pile	*index_two_three(t_stacks *stacks, t_pile *head, int index )
{
	if (index == 2)
	{
		stacks->stack_a = rotate_stack(&stacks->stack_a);
		instructions(&stacks->inst, 5);
		stacks->stack_a = swap_stack(&stacks->stack_a);
		instructions(&stacks->inst, 1);
		head = stacks->stack_a->next;
		stacks->stack_b = push_stack(&stacks->stack_b, &stacks->stack_a);
		stacks->stack_a = head;
		instructions(&stacks->inst, 4);
	}
	else
	{
		stacks->stack_a = reverse_rotate_stack(&stacks->stack_a);
		instructions(&stacks->inst, 7);
		stacks->stack_a = reverse_rotate_stack(&stacks->stack_a);
		instructions(&stacks->inst, 7);
		head = stacks->stack_a->next;
		stacks->stack_b = push_stack(&stacks->stack_b, &stacks->stack_a);
		stacks->stack_a = head;
		instructions(&stacks->inst, 4);
	}
	return (head);
}

t_pile	*index_last(t_stacks *stacks, t_pile *head)
{
	stacks->stack_a = reverse_rotate_stack(&stacks->stack_a);
	instructions(&stacks->inst, 7);
	head = stacks->stack_a->next;
	stacks->stack_b = push_stack(&stacks->stack_b, &stacks->stack_a);
	stacks->stack_a = head;
	instructions(&stacks->inst, 4);
	return (head);
}

t_pile	*index_zo_second(t_stacks *stacks, t_pile *head, int index)
{
	if (index == 0)
	{
		head = stacks->stack_a->next;
		stacks->stack_b = push_stack(&stacks->stack_b, &stacks->stack_a);
		stacks->stack_a = head;
		instructions(&stacks->inst, 4);
	}
	else
	{
		stacks->stack_a = swap_stack(&stacks->stack_a);
		head = stacks->stack_a->next;
		instructions(&stacks->inst, 1);
		stacks->stack_b = push_stack(&stacks->stack_b, &stacks->stack_a);
		stacks->stack_a = head;
		instructions(&stacks->inst, 4);
	}
	return (head);
}

t_pile	*index_last_second(t_stacks *stacks, t_pile *head, int index)
{
	if (index == 2)
	{
		stacks->stack_a = reverse_rotate_stack(&stacks->stack_a);
		instructions(&stacks->inst, 7);
		stacks->stack_a = reverse_rotate_stack(&stacks->stack_a);
		instructions(&stacks->inst, 7);
		head = stacks->stack_a->next;
		stacks->stack_b = push_stack(&stacks->stack_b, &stacks->stack_a);
		stacks->stack_a = head;
		instructions(&stacks->inst, 4);
	}
	else
	{
		stacks->stack_a = reverse_rotate_stack(&stacks->stack_a);
		instructions(&stacks->inst, 7);
		head = stacks->stack_a->next;
		stacks->stack_b = push_stack(&stacks->stack_b, &stacks->stack_a);
		stacks->stack_a = head;
		instructions(&stacks->inst, 4);
	}
	return (head);
}
