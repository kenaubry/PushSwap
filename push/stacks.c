/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <kenaubry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:04:34 by kenaubry          #+#    #+#             */
/*   Updated: 2022/07/06 17:04:37 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_pile	*new_stack(int n)
{
	t_pile	*new;

	new = (t_pile *)malloc(sizeof(t_pile));
	if (!new)
		exit(1);
	new->data = n;
	new->next = NULL;
	return (new);
}

t_stacks	*init_stacks(void)
{
	t_stacks	*stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		exit(1);
	ft_bzero(stacks, sizeof(t_stacks));
	stacks->stack_b = NULL;
	stacks->inst = NULL;
	return (stacks);
}

void	free_stack(t_pile **stacks)
{
	t_pile	*tmp;

	while (*stacks != NULL)
	{
		tmp = (*stacks)->next;
		free(*stacks);
		*stacks = tmp;
	}
	free(*stacks);
	*stacks = NULL;
}

void	free_all(t_stacks	*stacks)
{
	free_stack(&stacks->stack_a);
	free_stack(&stacks->stack_b);
	free_stack(&stacks->inst);
	free(stacks);
}

void	print_stack(t_pile **stacks)
{
	t_pile	*e;

	e = *stacks;
	while (e != NULL)
	{
		ft_printf("d=%d ", e->data);
		e = e->next;
	}
	ft_printf("\n");
}
