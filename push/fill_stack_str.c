/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <kenaubry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:03:36 by kenaubry          #+#    #+#             */
/*   Updated: 2022/07/06 17:03:39 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_count(char *s, t_stacks *stacks, t_ea_sa *ea_sa)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ' && s[i] != '\0')
			i++;
		else if (((s[i] > 47 && s[i] < 58) || s[i] == 43 || s[i] == 45)
			&& (i == 0 || s[i - 1] == ' ') && s[i] != '\0')
		{
			i++;
			k++;
		}
		else if ((s[i] < 48 || s[i] > 57) && s[i] != 32)
		{
			write(2, "Error\n", 6);
			free(ea_sa);
			free_all(stacks);
			exit(1);
		}
		else if (s[i] > 47 && s[i] < 58 && s[i] != '\0')
			i++;
	}
	return (k);
}

static char	*ft_find_number(char *str, int j)
{
	int		k;
	int		p;
	char	*s;

	k = 0;
	p = j;
	while (str[j] == ' ' && str[j] != '\0')
	{
		j++;
		p++;
	}
	while (((str[j] > 47 && str[j] < 58) || str[j] == 43 || str[j] == 45)
		&& str[j] != '\0')
	{
		j++;
		k++;
	}
	s = ft_strsub(str, p, k);
	printf("s = %s\n", s);
	return (s);
}

static int	ft_next_number(char *str, int j)
{
	while (str[j] == ' ' && str[j] != '\0')
		j++;
	while (((str[j] > 47 && str[j] < 58) || str[j] == 43 || str[j] == 45)
		&& str[j] != '\0')
		j++;
	return (j);
}

static int	*ft_fill_tab(char *str, int n, t_stacks *stacks, t_ea_sa *ea_sa)
{
	int		*tab;
	int		i;
	char	*s;
	int		j;

	i = 0;
	j = 0;
	printf("ici\n");
	tab = (int *)malloc(sizeof(int) * (n + 1));
	if (!tab)
		exit(1);
	while (i < n)
	{
		s = ft_find_number(str, j);
		j = ft_next_number(str, j);
		tab[i] = ft_atoi(s, stacks, tab, ea_sa);
		free(s);
		s = NULL;
		i++;
	}
	return (tab);
}

t_pile	*fill_stack_str(char *argv, t_stacks *stacks)
{
	t_pile		*stack_a;
	t_ea_sa		*ea_sa;
	int			*tab;
	int			in[2];

	ea_sa = init_ea_sa();
	in[0] = ft_count(argv, stacks, ea_sa);
	if (in[0] == 0)
		free_exit(stacks, ea_sa);
	tab = ft_fill_tab(argv, in[0], stacks, ea_sa);
	printf("fidsjgioejhido\n");
	in[0]--;
	while (in[0] >= 0)
	{
		ea_sa->ea = new_stack(tab[in[0]]);
		in[1] = ft_count(argv, stacks, ea_sa);
		is_doublon_str(tab, in, stacks, ea_sa);
		ea_sa->ea->next = ea_sa->stack_a;
		ea_sa->stack_a = ea_sa->ea;
		in[0]--;
	}
	free(tab);
	stack_a = ea_sa->stack_a;
	free(ea_sa);
	return (stack_a);
}
