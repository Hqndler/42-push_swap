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

#include "../push_swap.h"

void	swap_a(t_pile **pile_a)
{
	int	tmp;

	tmp = (*pile_a)->value;
	(*pile_a)->value = (*pile_a)->next->value;
	(*pile_a)->next->value = tmp;
	write(1, "sa\n", 3);
}

// void	swap_b(t_pile **pile_b)
// {
// 	int	tmp;

// 	tmp = (*pile_b)->value;
// 	(*pile_b)->value = (*pile_b)->next->value;
// 	(*pile_b)->next->value = tmp;
// 	write(1, "sb\n", 3);
// }
