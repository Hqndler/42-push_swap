/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handler <handler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:45:11 by handler           #+#    #+#             */
/*   Updated: 2023/01/11 18:09:49 by handler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static
int	check_for_opti(t_pile **pile_a, t_pile **pile_b, int pos_a, int pos_b)
{
	int	i;
	int	length_a;
	int	length_b;

	i = 0;
	length_a = len(*pile_a);
	length_b = len(*pile_b);
	if ((pos_a <= (length_a / 2)) && (pos_b <= (length_b / 2)))
	{
		while (i <= (pos_a - 1) && i <= (pos_b - 1))
		{
			rotate_both(pile_a, pile_b);
			i++;
		}
	}
	if ((pos_a > (length_a / 2)) && (pos_b > (length_b / 2)))
	{
		while (i < (length_a - pos_a) && i < (length_b - pos_b))
		{
			reverse_rotate_both(pile_a, pile_b);
			i++;
		}
	}
	return (i);
}

static t_pile	*rr_rra(t_pile *pile_a, int pos_a, int i)
{
	if (pos_a <= (len(pile_a) / 2))
	{
		while (i <= pos_a - 1)
		{
			rotate_a(&pile_a, 1);
			++i;
		}
	}
	else
	{
		while (i < (len(pile_a) - pos_a))
		{
			reverse_rotate_a(&pile_a, 1);
			++i;
		}
	}
	return (pile_a);
}

void	insertion_sort(t_pile **p_a, t_pile **p_b, int b_move, t_mq **mq)
{
	int	pos_a;
	int	pos_b;
	int	i;

	pos_a = get_pos_to_place((*p_a), b_move);
	pos_b = get_index((*p_b), b_move);
	i = check_for_opti(p_a, p_b, pos_a, pos_b);
	while ((*p_b)->value != b_move)
	{
		if (pos_b <= (len((*p_b)) / 2))
			rotate_b(p_b, 1);
		else
			reverse_rotate_b(p_b, 1);
	}
	(*p_a) = rr_rra((*p_a), pos_a, i);
	push_a(p_a, p_b, mq);
}

void	push_b_optimize(t_pile *pile_a, t_pile *pile_b, t_mq *mq)
{
	while (inner(pile_a, mq->q1, mq->q2) && mq->len >= 8)
	{
		if (pile_a->value >= mq->q1 && pile_a->value <= mq->med)
		{
			push_b(&pile_a, &pile_b, &mq);
			rotate_b(&pile_b, 1);
			continue ;
		}
		if (pile_a->value <= mq->q2 && pile_a->value >= mq->med)
		{
			push_b(&pile_a, &pile_b, &mq);
			continue ;
		}
		else
			rotate_a(&pile_a, 1);
	}
	while (len(pile_a) > 3)
	{
		push_b(&pile_a, &pile_b, &mq);
		if (pile_b->value < mq->med)
			rotate_b(&pile_b, 1);
	}
	if (!(is_sorted(pile_a)))
		sort_three(&pile_a);
	push_a_optimize(pile_a, pile_b, mq);
}

void	push_a_optimize(t_pile *pile_a, t_pile *pile_b, t_mq *mq)
{
	mq->len -= 3;
	while (mq->len)
	{
		insertion_sort(&pile_a, &pile_b, get_best_move(pile_a, pile_b), &mq);
		mq->len--;
	}
	replace_pile(&pile_a);
	pile_b = NULL;
	free_everything(&pile_a, &pile_b, &mq);
	exit(1);
}
