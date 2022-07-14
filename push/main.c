/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <kenaubry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:03:49 by kenaubry          #+#    #+#             */
/*   Updated: 2022/07/06 17:03:50 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ADD FLAGS MAKEFILE

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = init_stacks();
	if (argc == 1)
	{
		free_all(stacks);
		exit(0);
	}
	if (argc == 2)
		stacks->stack_a = fill_stack_str(argv[1], stacks);
	else
		stacks->stack_a = fill_stack(argc, argv, stacks);
	if (is_stack_sort(&stacks->stack_a, 1) != 0)
		algo(stacks);
	free_all(stacks);
	return (0);
}
