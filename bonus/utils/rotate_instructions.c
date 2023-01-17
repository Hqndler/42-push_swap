/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handler <handler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:46:26 by handler           #+#    #+#             */
/*   Updated: 2023/01/11 11:36:21 by handler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	rotate_a(t_pile **pile_a, int print)
{
	if (*pile_a && (*pile_a)->next != *pile_a)
	{
		*pile_a = (*pile_a)->next;
		if (print)
			write(1, "ra\n", 3);
	}
}

void	rotate_b(t_pile **pile_b, int print)
{
	if (*pile_b && (*pile_b)->next != *pile_b)
	{
		*pile_b = (*pile_b)->next;
		if (print)
			write(1, "rb\n", 3);
	}
}

void	rotate_both(t_pile **p_a, t_pile **p_b)
{
	if (*p_a && (*p_a)->next != *p_a && *p_b && (*p_b)->next != *p_b)
	{
		rotate_a(p_a, 0);
		rotate_b(p_b, 0);
	}
}
