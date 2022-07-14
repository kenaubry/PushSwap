/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenaubry <kenaubry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:05:28 by kenaubry          #+#    #+#             */
/*   Updated: 2022/07/06 17:05:29 by kenaubry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	RESTE A FAIRE :
//
//	- reorganiser les fonctions et essayer d'avoir un code plus concis
//
//	- remplacer les fonctions interdites types printf, ft_atoi...
//
//	- check avec plusieurs testeurs, tous les cas d'erreurs
//
//	- verifier la norme

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	<stdio.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	"../printf/ft_printf.h"

typedef struct s_pile
{
	struct s_pile	*next;
	int				data;
}					t_pile;

typedef struct s_stacks
{
	struct s_pile	*stack_a;
	struct s_pile	*stack_b;
	struct s_pile	*inst;
	struct s_pile	*ea;
}					t_stacks;

typedef struct s_nb
{
	int	n;
	int	i;
}				t_nb;

typedef struct s_ea_sa
{
	struct s_pile	*ea;
	struct s_pile	*stack_a;
}				t_ea_sa;

// utils
void				ft_bzero(void *s, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_atoi(const char *str, t_stacks *stacks, int *tab, t_ea_sa *ea_sa);
char				*ft_strdup(const char *src);

// free stack_a, stack_b, inst et la structure contenant le tout
void				free_all(t_stacks	*stacks);

// créé une nouvelle pile
t_pile				*new_stack(int n);

// initialise une nouvelle pile
t_stacks			*init_stacks(void);
t_ea_sa				*init_ea_sa(void);

// free une pile
void				free_stack(t_pile **stacks);

// echange les deux premiers elements de la stack
t_pile				*swap_stack(t_pile **bi);

// envoie le premier element d'une stack dans l'autre
t_pile				*push_stack(t_pile **bf, t_pile **bi);

// le premier element de la stack devient le dernier
t_pile				*rotate_stack(t_pile **bi);

// le dernier element de la stack devient le premier
t_pile				*reverse_rotate_stack(t_pile **bi);

// algorithme
int					algo(t_stacks *stacks);

// vérifie les doublons d'éléments dans la string donnée
void				is_doublon_str(int *tab, int *in, \
					t_stacks *stacks, t_ea_sa *ea_sa);

// remplie la pile avec les differents arguments
t_pile				*fill_stack(int argc, char **argv, t_stacks *stacks);

// remplie la pile en splitant l'argument donné
t_pile				*fill_stack_str(char *argv, t_stacks *stacks);

// affiche le contenu d'une pile
void				print_stack(t_pile **stacks);

void				ft_rr(t_pile **bi);

// trouve la longueur de la pile
int					size_stack(t_pile **bi);

// trie la pile A
void				ft_work_a(t_stacks *stacks, int len);

// trie la pile B
void				ft_work_b(t_stacks *stacks, int len);

// verifie si la pile est triée ou non
int					is_stack_sort(t_pile **stacks, int pile);

// trie tab contenant elems de la pile pr trouver la mediane
void				ft_sort_tab(int *tab, int len);

// cherche la mediane de la pile
int					ft_median(t_pile **stacks, int pile, int n);

// regarde si le nombre donné est < ou > à la mediane
int					ft_compare_with_median(t_stacks *stacks, int n, \
					int median, int stack);

// trie une pile de 2 éléments
void				ft_sort_2_elem(t_stacks *stacks);

// trie une pile de 3 éléments
void				ft_sort_3_elem(t_stacks *stacks);
void				ft_sort_5_elem(t_stacks *stacks);
// trie lorsque la pile se réduit à 3 éléments ou moins
void				ft_sort_min_a(t_stacks *stacks);
void				ft_sort_min_b(t_stacks *stacks);

// stocke la suite d'instructions
void				instructions(t_pile **init, int n);

// trouve l'index des deux plus petits dans une stack de 5
t_pile				*index_zero_one(t_stacks *stacks, t_pile *head, int index );
t_pile				*index_two_three(t_stacks *stacks, \
						t_pile *head, int index );
t_pile				*index_last(t_stacks *stacks, t_pile *head);
t_pile				*index_zo_second(t_stacks *stacks, t_pile *head, int index);
t_pile				*index_last_second(t_stacks *stacks, \
						t_pile *head, int index);

void				free_exit(t_stacks *stacks, t_ea_sa *ea_sa);

#endif