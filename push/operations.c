/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <kenaubry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:04:18 by kenaubry          #+#    #+#             */
/*   Updated: 2022/07/06 17:04:19 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/push_swap.h"

t_pile	*swap_stack(t_pile **bi)
{
	t_pile		*elem;
	int			tmp;

	elem = *bi;
	if (elem == NULL || elem->next == NULL)
		return (*bi);
	tmp = elem->next->data;
	elem->next->data = elem->data;
	elem->data = tmp;
	*bi = elem;
	return (*bi);
}

t_pile	*push_stack(t_pile **bf, t_pile **bi)
{
	t_pile		*elem;

	elem = *bi;
	if (elem == NULL)
		return (*bf);
	elem->next = *bf;
	*bf = elem;
	return (*bf);
}

t_pile	*rotate_stack(t_pile **bi)
{
	t_pile		*elem;
	int			tmp;

	elem = *bi;
	tmp = elem->data;
	if (elem == NULL || elem->next == NULL)
		return (*bi);
	while (elem->next != NULL)
	{
		elem->data = elem->next->data;
		elem = elem->next;
	}
	elem->data = tmp;
	return (*bi);
}

void	ft_rr(t_pile **bi)
{
	t_pile	*elem;
	int		tmp;
	int		tmp2;
	int		i;

	elem = *bi;
	i = 0;
	while (elem != NULL)
	{
		if (i % 2 != 0)
		{
			tmp2 = elem->data;
			elem->data = tmp;
		}
		else if (i % 2 == 0)
		{
			tmp = elem->data;
			elem->data = tmp2;
		}
		i++;
		elem = elem->next;
	}
}

t_pile	*reverse_rotate_stack(t_pile **bi)
{
	t_pile		*elem;
	int			tmp0;

	elem = *bi;
	if (elem == NULL || elem->next == NULL)
		return (*bi);
	while (elem->next != NULL)
		elem = elem->next;
	tmp0 = elem->data;
	ft_rr(bi);
	elem = *bi;
	elem->data = tmp0;
	return (*bi);
}
