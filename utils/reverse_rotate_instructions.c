/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_instructions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handler <handler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:56:24 by handler           #+#    #+#             */
/*   Updated: 2023/01/11 11:36:40 by handler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate_a(t_pile **pile_a, int print)
{
	if (*pile_a && (*pile_a)->prev != *pile_a)
	{
		*pile_a = (*pile_a)->prev;
		if (print)
			write(1, "rra\n", 4);
	}
}

void	reverse_rotate_b(t_pile **pile_b, int print)
{
	if (*pile_b && (*pile_b)->prev != *pile_b)
	{
		*pile_b = (*pile_b)->prev;
		if (print)
			write(1, "rrb\n", 4);
	}
}

void	reverse_rotate_both(t_pile **p_a, t_pile **p_b)
{
	if (*p_a && (*p_a)->prev != *p_a && *p_b && (*p_b)->prev != *p_b)
	{
		reverse_rotate_a(p_a, 0);
		reverse_rotate_b(p_b, 0);
		write(1, "rrr\n", 4);
	}
}
