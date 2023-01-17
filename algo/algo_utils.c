/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handler <handler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:22:19 by handler           #+#    #+#             */
/*   Updated: 2023/01/11 16:45:16 by handler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	count_move(t_pile *pile_a, t_pile *pile_b, int elem)
{
	int	count;
	int	index;

	index = get_index(pile_b, elem);
	count = 1;
	if (index > 1 && index > (len(pile_b) / 2))
		count += len(pile_b) - index - 1;
	else if (index > 1 && index <= (len(pile_b) / 2))
		count += index - 1;
	index = get_pos_to_place(pile_a, elem);
	if (index > 1 && index > (len(pile_a) / 2))
		count += len(pile_a) - index - 1;
	else if (index > 1 && index <= (len(pile_a) / 2))
		count += index - 1;
	return (count);
}

int	get_best_move(t_pile *pile_a, t_pile *pile_b)
{
	int		best_move_elem;
	int		move_count;
	int		best_move_count;
	t_pile	*tmp;

	best_move_elem = pile_b->value;
	best_move_count = count_move(pile_a, pile_b, best_move_elem);
	tmp = pile_b->next;
	while (tmp != pile_b && tmp != NULL)
	{
		move_count = count_move(pile_a, pile_b, tmp->value);
		if (move_count < best_move_count)
		{
			best_move_count = move_count;
			best_move_elem = tmp->value;
		}
		tmp = tmp->next;
	}
	return (best_move_elem);
}

int	is_sorted(t_pile *pile)
{
	int	i;
	int	length;

	length = len(pile);
	if (length > 0)
	{
		i = 1;
		while (i++ < length)
		{
			if (pile->value > pile->next->value)
				return (0);
			pile = pile->next;
		}
		return (1);
	}
	return (0);
}

int	inner(t_pile *pile, int q1, int q2)
{
	t_pile	*tmp;
	int		length;
	int		i;

	length = len(pile);
	i = 0;
	tmp = pile;
	while (i < length)
	{
		if (q1 <= tmp->value && tmp->value <= q2)
			return (1);
		tmp = tmp->next;
		++i;
	}
	return (0);
}

void	replace_pile(t_pile **pile)
{
	int		m;
	int		index;
	t_pile	*pile_a;

	pile_a = *pile;
	m = get_min(pile_a);
	if (pile_a->value != m)
	{
		index = get_index(pile_a, m);
		if (index <= len(pile_a) / 2)
			while (pile_a->value != m)
				rotate_a(&pile_a, 1);
		else
			while (pile_a->value != m)
				reverse_rotate_a(&pile_a, 1);
	}
	(*pile) = pile_a;
}
