/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handler <handler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:07:40 by handler           #+#    #+#             */
/*   Updated: 2023/01/12 19:07:40 by handler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

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

static char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = -1;
	while (s1 && s1[++j])
		str[++i] = s1[j];
	j = -1;
	while (s2[++j])
		str[++i] = s2[j];
	str[i + 1] = '\0';
	if (s1)
		free(s1);
	return (str);
}


static void	do_cmd(t_pile **pile_a, t_pile **pile_b, char **cmd, t_mq **mq)
{
	if (ft_strcmp(*cmd, "pa") == 1)
		push_a(pile_a, pile_b, mq);
	else if (ft_strcmp(*cmd, "pb") == 1)
		push_b(pile_a, pile_b, mq);
	else if (ft_strcmp(*cmd, "sa") == 1)
		swap_a(pile_a);
	else if (ft_strcmp(*cmd, "sb") == 1)
		swap_b(pile_b);
	else if (ft_strcmp(*cmd, "ss") == 1)
		swap_both(pile_a, pile_b);
	else if (ft_strcmp(*cmd, "rb") == 1)
		rotate_b(pile_b, 0);
	else if (ft_strcmp(*cmd, "ra") == 1)
		rotate_a(pile_a, 0);
	else if (ft_strcmp(*cmd, "rr") == 1)
		rotate_both(pile_a, pile_b);
	else if (ft_strcmp(*cmd, "rra") == 1)
		reverse_rotate_a(pile_a, 1);
	else if (ft_strcmp(*cmd, "rrb") == 1)
		reverse_rotate_b(pile_b, 1);
	else if (ft_strcmp(*cmd, "rrr") == 1)
		reverse_rotate_both(pile_a, pile_b);
	else
		exit_free(pile_a, pile_b, mq, cmd);
}

void	read_input(t_pile **pile_a, t_pile **pile_b, t_mq **mq)
{
	int		res;
	char	*line;
	char	buffer[2];

	res = 1;
	line = NULL;
	while (res > 0)
	{
		res = read(0, buffer, 1);
		buffer[res] = '\0';
		if (res == 0)
			return ;
		else if (buffer[0] != '\n')
			line = ft_strjoin(line, buffer);
		else
		{
			do_cmd(pile_a, pile_b, &line, mq);
			free(line);
			line = NULL;
		}
	}
}
