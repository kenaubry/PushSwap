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

static void	ft_check_doublon(char **argv, int *in, t_stacks *stacks, t_pile *ea)
{
	char	*strdup_bequille;

	in[0]--;
	while (in[0] > 0)
	{
		strdup_bequille = strdup(argv[in[0]]);
		if (in[1] == ft_atoi(strdup_bequille, stacks, NULL, NULL))
		{
			write(2, "Error\n", 6);
			free(strdup_bequille);
			free_all(stacks);
			free_stack(&ea);
			exit(1);
		}
		free(strdup_bequille);
		in[0]--;
	}
}

void	is_doublon_str(int *tab, int *in, t_stacks *stacks, \
					t_ea_sa *ea_sa)
{
	int	j;

	if (in[0] != 0)
		j = in[0] - 1;
	else
		j = 0;
	while (j >= 0)
	{
		if (tab[in[0]] == tab[j] && in[1] != 1 && j != in[0])
		{
			write(2, "Error\n", 6);
			free_all(stacks);
			free(tab);
			free_stack(&ea_sa->ea);
			free_stack(&ea_sa->stack_a);
			free(ea_sa);
			exit(1);
		}
		j--;
	}
}

t_pile	*fill_stack(int argc, char **argv, t_stacks	*stacks)
{
	t_pile		*ea;
	t_pile		*stack_a;
	char		*strdup_bequille;
	int			in[2];

	ea = NULL;
	stack_a = NULL;
	in[0] = argc - 1;
	in[1] = 1;
	while (in[0] > 0)
	{
		strdup_bequille = ft_strdup(argv[in[0]]);//attention au strdup
		in[1] = ft_atoi(strdup_bequille, stacks, NULL, NULL);
		free(strdup_bequille);
		ft_check_doublon(argv, in, stacks, ea);
		ea = new_stack(in[1]);
		ea->next = stack_a;
		stack_a = ea;
		in[0]--;
	}
	print_stack(&stack_a);
	return (stack_a);
}
