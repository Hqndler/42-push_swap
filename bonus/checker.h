/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handler <handler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:42:53 by handler           #+#    #+#             */
/*   Updated: 2023/01/12 18:42:53 by handler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_pile
{
	int				value;
	struct s_pile	*prev;
	struct s_pile	*next;
}					t_pile;

typedef struct s_mq
{
	int	med;
	int	q1;
	int	q2;
	int	len;
}		t_mq;

// list_utils
int			new_element(int nbr, t_pile **elem);
void		modify_element(t_pile **elem, t_pile *prev, t_pile *next);
int			add_to_list(t_pile **pile, int nbr);
void		free_pile(t_pile **pile);
int			len(t_pile *pile);

// getter
int			get_index(t_pile *pile, int elem);
int			get_min(t_pile *pile);
int			get_max(t_pile *pile);
int			get_pos_to_place(t_pile *pile, int elem);
int			get_best_move(t_pile *pile_a, t_pile *pile_b);

// swap
void		swap_a(t_pile **pile_a);
void		swap_b(t_pile **pile_b);
void		swap_both(t_pile **pile_a, t_pile **pile_b);

// push
void		push_a(t_pile **pile_a, t_pile **pile_b, t_mq **mq);
void		push_b(t_pile **pile_a, t_pile **pile_b, t_mq **mq);

// rotate
void		rotate_both(t_pile **p_a, t_pile **p_b);
void		rotate_a(t_pile **pile_a, int print);
void		rotate_b(t_pile **pile_b, int print);

void		reverse_rotate_both(t_pile **p_a, t_pile **p_b);
void		reverse_rotate_a(t_pile **pile_a, int print);
void		reverse_rotate_b(t_pile **pile_b, int print);

int		ft_strcmp(const char *s1, const char *s2);
void		quick_sort(int array[], int low, int high);
void		get_median_quartil(char **spl, t_mq **mq, int *error);
void		fill_mq(t_mq **mq, int len, int array[]);
int			is_sorted(t_pile *pile);
size_t		ft_strlen(const char *s);
void		read_input(t_pile **pile_a, t_pile **pile_b, t_mq **mq);
void		exit_free(t_pile **pile_a, t_pile **pile_b, t_mq **mq, char **cmd);
long long	ft_atoi(const char *nptr);
int			ft_atoi_and_check(const char *nptr, int *error);
char		**ft_split(char const *s, char c);
char		*ft_strdup(const char *src);
void		free_everything(t_pile **pile_a, t_pile **pile_b, t_mq **mq);

void	print_list(t_pile *head);

#endif