/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medianne.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handler <handler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:13:59 by handler           #+#    #+#             */
/*   Updated: 2023/01/11 13:27:12 by handler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	exit_free(t_pile **pile_a, t_pile **pile_b, t_mq **mq, char **cmd)
{
	if (*cmd)
		free(*cmd);
	free_pile(pile_a);
	free_pile(pile_b);
	free(*mq);
	write(2, "Error\n", 6);
	exit(1);
}

void	fill_mq(t_mq **mq, int len, int array[])
{
	if (len % 2 == 0)
		(*mq)->med = len / 2;
	(*mq)->q1 = (((*mq)->med) + 1) / 2;
	if ((*mq)->med % 2 == 0)
		(*mq)->q1 = ((*mq)->med) / 2;
	(*mq)->q2 = ((*mq)->med) + ((*mq)->q1);
	if (len > 5)
	{
		(*mq)->q1 = array[(*mq)->q1];
		(*mq)->q2 = array[(*mq)->q2];
	}
	else
	{
		(*mq)->q1 = 0;
		(*mq)->q2 = 0;
	}
}
