/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: handler <handler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 23:47:19 by handler           #+#    #+#             */
/*   Updated: 2023/01/11 16:02:44 by handler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static void	swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

static int	partition(int array[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[high];
	i = (low - 1);
	j = low;
	while (j < high)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
		j++;
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

void	quick_sort(int array[], int low, int high)
{
	int	pivot;

	if (low < high)
	{
		pivot = partition(array, low, high);
		quick_sort(array, low, pivot - 1);
		quick_sort(array, pivot + 1, high);
	}
}

/*
	permet de checker s'il y a des doublons, si oui len de mq sera mise à 0
	met medianne quartil 1 et 2 dans la struc mq
*/

static void	doublon_and_fin(int array[], int len, t_mq **mq)
{
	int	i;
	int	tmp;
	int	l;

	i = 0;
	tmp = array[0];
	l = 1;
	while (++i < len)
	{
		if (array[i] == tmp)
			l = 0;
		tmp = array[i];
	}
	(*mq)->len = len;
	if (!l)
		(*mq)->len = l;
	(*mq)->med = (len + 1) / 2;
	fill_mq(mq, len, array);
}

void	get_median_quartil(char **spl, t_mq **mq, int *error)
{
	int		len;
	int		i;
	int		*tab;

	len = 0;
	while (spl[len] && spl != NULL)
		++len;
	tab = malloc(sizeof(int) * len);
	if (!tab || !spl)
	{
		(*mq) = NULL;
		return ;
	}
	i = len;
	while (--i != -1)
	{
		tab[i] = ft_atoi_and_check(spl[i], error);
		free(spl[i]);
	}
	free(spl);
	quick_sort(tab, 0, len - 1);
	doublon_and_fin(tab, len, mq);
	(*mq)->med = tab[((*mq)->med) - 1];
	free(tab);
}
