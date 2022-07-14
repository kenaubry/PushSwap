/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <kenaubry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:03:29 by kenaubry          #+#    #+#             */
/*   Updated: 2022/07/06 17:03:31 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_check_doublon(char **argv, int i, int n, t_stacks *stacks, \
							t_pile *ea)
{
	char	*strdup_bequille;

	i--;
	while (i > 0)
	{
		strdup_bequille = strdup(argv[i]);
		if (n == ft_atoi(strdup_bequille, stacks, NULL))
		{
			write(2, "Error\n", 6);
			free(strdup_bequille);
			free_all(stacks);
			free_stack(&ea);
			exit(1);
		}
		free(strdup_bequille);
		i--;
	}
}

void	is_doublon_str(int *tab, int i, int n, t_stacks *stacks, \
					t_pile *stack_a, t_pile *ea)
{
	int	j;

	if (i != 0)
		j = i - 1;
	else
		j = 0;
	while (j >= 0)
	{
		if (tab[i] == tab[j] && n != 1 && j != i)
		{
			write(2, "Error\n", 6);
			free_all(stacks);
			free(tab);
			free_stack(&ea);
			free_stack(&stack_a);
			exit(1);
		}
		j--;
	}
}

t_pile	*fill_stack(int argc, char **argv, t_stacks	*stacks)
{
	t_pile		*ea;
	t_pile		*stack_a;
	int			n;
	int			i;
	char		*strdup_bequille;

	ea = NULL;
	stack_a = NULL;
	i = argc - 1;
	while (i > 0)
	{
		strdup_bequille = strdup(argv[i]);//attention au strdup
		n = ft_atoi(strdup_bequille, stacks, NULL);
		free(strdup_bequille);
		ft_check_doublon(argv, i, n, stacks, ea);
		ea = new_stack(n);
		ea->next = stack_a;
		stack_a = ea;
		i--;
	}
	return (stack_a);
}
