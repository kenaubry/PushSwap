/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <kenaubry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:04:44 by kenaubry          #+#    #+#             */
/*   Updated: 2022/07/06 17:04:46 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	size_stack(t_pile **bi)
{
	t_pile	*elem;
	int		i;

	elem = *bi;
	i = 0;
	while (elem != NULL)
	{
		i++;
		elem = elem->next;
	}
	return (i);
}

int	is_stack_sort(t_pile **stacks, int pile)
{
	int		i;
	t_pile	*e;
	t_pile	*next;

	i = 0;
	e = *stacks;
	next = e->next;
	while (i < size_stack(stacks) - 1)
	{
		if ((e->data < next->data && pile == 1)
			|| (e->data > next->data && pile == 2))
		{
			e = e->next;
			next = e->next;
			i++;
		}
		else
			return (1);
	}
	return (0);
}

void	free_exit(t_stacks *stacks)
{
	free_all(stacks);
	exit(0);
}
