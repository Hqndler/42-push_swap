/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handler <handler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:39:08 by handler           #+#    #+#             */
/*   Updated: 2023/01/11 17:04:59 by handler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	initialize_pile(t_pile **pile_a, t_pile **pile_b, char **spl)
{
	int	i;
	int	t;

	i = 0;
	*pile_a = NULL;
	*pile_b = NULL;
	if (!spl)
		return (-1);
	while (spl[i])
		i++;
	while (--i >= 0)
	{
		t = add_to_list(pile_a, ft_atoi(spl[i]));
		if (t == -1)
			return (-1);
		free(spl[i]);
	}
	free(spl);
	return (1);
}

static int	split_len(char **spl)
{
	int	i;

	i = -1;
	if (!spl)
		return (-1);
	while (spl[++i])
		free(spl[i]);
	free(spl);
	return (i);
}

static char	**useless(int argc, char **argv)
{
	int		i;
	char	**split;

	if (argc > 2)
	{
		i = 0;
		split = malloc(sizeof(char *) * argc);
		while (++i < argc)
		{
			if (split_len(ft_split(argv[i], ' ')) != 1 || !split)
			{
				i++;
				while (--i != 0 || split != NULL)
					free(split[i]);
				free(split);
				return (NULL);
			}
			split[i - 1] = ft_strdup(argv[i]);
		}
		split[argc - 1] = NULL;
		return (split);
	}
	if (argc == 2)
		return (ft_split(argv[1], ' '));
	return (NULL);
}

// void	print_list(t_pile *head)
// {
// 	t_pile	*current;

// 	if (head == NULL)
// 	{
// 		printf("head est null");
// 		return ;
// 	}
// 	current = head;
// 	while (current->next != head)
// 	{
// 		printf("[%d] ", current->value);
// 		current = current->next;
// 	}
// 	printf("[%d]\n", current->value);
// }

static void	launch_algo(t_pile *pile_a, t_pile *pile_b, t_mq *mq)
{
	if (mq->len == 2)
		if (pile_a->value > pile_a->next->value)
			write(1, "sa\n", 3);
	if (mq->len > 2)
		if (!is_sorted(pile_a))
			push_b_optimize(pile_a, pile_b, mq);
	free_everything(&pile_a, &pile_b, &mq);
	exit(1);
}
// printf("len %d med %d q1 %d q2 %d\n", mq->len, mq->med, mq->q1, mq->q2);

int	main(int argc, char **argv)
{
	t_mq	*mq;
	int		error;
	t_pile	*pile_a;
	t_pile	*pile_b;

	if (argc == 1)
		exit(1);
	mq = malloc(sizeof(t_mq));
	if (!mq)
		return (1);
	error = 0;
	get_median_quartil(useless(argc, argv), &mq, &error);
	if (error || mq->len == 0 || !mq)
	{
		write(2, "Error\n", 6);
		if (mq)
			free(mq);
		return (1);
	}
	if (initialize_pile(&pile_a, &pile_b, useless(argc, argv)) == 1)
		launch_algo(pile_a, pile_b, mq);
	free_pile(&pile_a);
	free(mq);
	return (0);
}
