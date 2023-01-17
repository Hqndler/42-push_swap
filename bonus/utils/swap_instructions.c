/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handler <handler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:58:24 by handler           #+#    #+#             */
/*   Updated: 2023/01/04 15:50:37 by handler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	swap_a(t_pile **pile_a)
{
	int	tmp;

	if (!(*pile_a))
	tmp = (*pile_a)->value;
	(*pile_a)->value = (*pile_a)->next->value;
	(*pile_a)->next->value = tmp;
}

void	swap_b(t_pile **pile_b)
{
	int	tmp;

	if (!(*pile_b))
		return ;
	tmp = (*pile_b)->value;
	(*pile_b)->value = (*pile_b)->next->value;
	(*pile_b)->next->value = tmp;
}

void	swap_both(t_pile **pile_a, t_pile **pile_b)
{
	swap_a(pile_a);
	swap_a(pile_b);
}
