/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <kenaubry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:03:15 by kenaubry          #+#    #+#             */
/*   Updated: 2022/07/06 17:03:20 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// stocke les instructions
void	instructions(t_pile **inst, int n)
{
	t_pile	*elem;
	t_pile	*new;

	elem = *inst;
	if (elem != NULL)
	{
		while (elem->next != NULL)
			elem = elem->next;
		new = new_stack(n);
		elem->next = new;
	}
	else
		*inst = new_stack(n);
}

// depend de print_instructions, affiche les operations stockées
static void	print_instructions_bis(t_pile *e)
{
	if (e->data == 3)
		ft_printf("pa\n");
	else if (e->data == 4)
		ft_printf("pb\n");
	else if (e->data == 5)
		ft_printf("ra\n");
	else if (e->data == 6)
		ft_printf("rb\n");
	else if (e->data == 7)
		ft_printf("rra\n");
	else if (e->data == 8)
		ft_printf("rrb\n");
}

// affiche les operations stockées
static void	print_instructions(t_stacks *stacks)
{
	t_pile		*e;
	t_pile		*suiv;

	e = stacks->inst;
	while (e != NULL)
	{
		if (e->next != NULL)
			suiv = e->next;
		if (e->data == 1)
			ft_printf("sa\n");
		else if (e->data == 2 && suiv && suiv->data != 1)
			ft_printf("sb\n");
		else if ((e->data == 1 && suiv && suiv->data == 2)
			|| (e->data == 2 && suiv && suiv->data == 1))
			ft_printf("ss\n");
		else
			print_instructions_bis(e);
		e = e->next;
	}
}

// algorithm
int	algo(t_stacks *stacks)
{
	int	n;

	n = size_stack(&stacks->stack_a);
	if (n == 1)
		return (0);
	else if (n == 2)
		ft_sort_2_elem(stacks);
	else if (n == 3)
		ft_sort_3_elem(stacks);
	else if (n == 5)
		ft_sort_5_elem(stacks);
	else
		ft_work_a(stacks, size_stack(&stacks->stack_a));
	print_instructions(stacks);
	return (0);
}
