/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handler <handler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:43:28 by handler           #+#    #+#             */
/*   Updated: 2023/01/11 11:35:38 by handler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_index(t_pile *pile, int elem)
{
	t_pile	*tmp;
	int		i;

	i = 0;
	tmp = pile;
	while (tmp->next != pile)
	{
		if (tmp->value == elem)
			return (i);
		tmp = tmp->next;
		++i;
	}
	return (i);
}

int	get_min(t_pile *pile)
{
	int		min;
	t_pile	*tmp;

	tmp = pile->next;
	min = pile->value;
	while (tmp != pile && tmp != NULL)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp-> next;
	}
	return (min);
}

int	get_max(t_pile *pile)
{
	int		max;
	t_pile	*tmp;

	tmp = pile->next;
	max = pile->value;
	while (tmp != pile && tmp != NULL)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp-> next;
	}
	return (max);
}

int	get_pos_to_place(t_pile *pile, int elem)
{
	int		min;
	int		i;
	int		l;
	t_pile	*tmp;

	min = get_min(pile);
	if (elem > get_max(pile) || elem < min)
		return (get_index(pile, min));
	l = len(pile);
	i = -1;
	tmp = pile;
	while (++i < l)
	{
		if (tmp->prev->value < elem && elem < tmp->value)
			return (i);
		tmp = tmp->next;
	}
	return (0);
}
