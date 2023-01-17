/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handler <handler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:23:31 by handler           #+#    #+#             */
/*   Updated: 2023/01/09 15:39:07 by handler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	new_element(int nbr, t_pile **elem)
{
	(*elem) = malloc(sizeof(t_pile));
	if (!(*elem))
		return (-1);
	(*elem)->value = nbr;
	(*elem)->next = NULL;
	(*elem)->prev = NULL;
	return (1);
}

void	free_everything(t_pile **pile_a, t_pile **pile_b, t_mq **mq)
{
	free_pile(pile_a);
	free_pile(pile_b);
	free(*mq);
}

int	add_to_list(t_pile **pile, int nbr)
{
	t_pile	*elem;

	if (new_element(nbr, &elem) == -1)
		return (-1);
	if ((*pile) == NULL)
	{
		(*pile) = elem;
		(*pile)->next = *pile;
		(*pile)->prev = *pile;
	}
	else
	{
		elem->prev = (*pile)->prev;
		elem->next = (*pile);
		(*pile)->prev->next = elem;
		(*pile)->prev = elem;
		(*pile) = elem;
	}
	return (1);
}

void	free_pile(t_pile **pile)
{
	t_pile	*current;
	t_pile	*tmp;

	if ((*pile) == NULL)
		return ;
	current = (*pile);
	while (current->next != (*pile))
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	free(current);
	*pile = NULL;
}

int	len(t_pile *pile)
{
	t_pile	*tmp;
	int		i;

	if ((pile) && pile->next != pile)
	{
		tmp = (pile)->next;
		i = 1;
		while (tmp != (pile))
		{
			++i;
			tmp = tmp->next;
		}
		return (i);
	}
	return (0);
}
