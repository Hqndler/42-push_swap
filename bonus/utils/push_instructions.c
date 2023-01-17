/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handler <handler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:05:01 by handler           #+#    #+#             */
/*   Updated: 2023/01/11 18:05:42 by handler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	push_a(t_pile **pile_a, t_pile **pile_b, t_mq **mq)
{
	t_pile	*tmp;

	if (!(*pile_b))
		return ;
	if (add_to_list(pile_a, (*pile_b)->value) == -1)
	{
		free_everything(pile_a, pile_b, mq);
		exit(1);
	}
	if (*pile_b == (*pile_b)->next)
	{
		free(*pile_b);
		*pile_b = NULL;
		return ;
	}
	tmp = (*pile_b);
	(*pile_b)->prev->next = (*pile_b)->next;
	(*pile_b)->next->prev = (*pile_b)->prev;
	(*pile_b) = (*pile_b)->next;
	free(tmp);
}

void	push_b(t_pile **pile_a, t_pile **pile_b, t_mq **mq)
{
	t_pile	*tmp;

	if (!(*pile_a))
		return ;
	if (add_to_list(pile_b, (*pile_a)->value) == -1)
	{
		free_everything(pile_a, pile_b, mq);
		exit(1);
	}
	tmp = (*pile_a);
	(*pile_a)->prev->next = (*pile_a)->next;
	(*pile_a)->next->prev = (*pile_a)->prev;
	(*pile_a) = (*pile_a)->next;
	free(tmp);
}
