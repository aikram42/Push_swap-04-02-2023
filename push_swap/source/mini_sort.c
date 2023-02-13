/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:36:39 by aikram            #+#    #+#             */
/*   Updated: 2023/02/03 20:51:00 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*two(int *a)
{
	if (a[0] > a[1])
		swap(&a[0], &a[1], 'a');
	return (a);
}

void	three(int *a, int l, int i)
{
	if (a[i] > a[i + 2] && a[i] > a[i + 1])
		rot(a, l, i, 'a');
	if (a[i + 2] < a[i] || a[i + 2] < a[i + 1])
		rrot(a, l, i, 'a');
	if (a[i] > a[i + 1])
		swap(&a[i], &a[i + 1], 'a');
}

void	four(int *a, int l, int i)
{
	int	j[4];

	j[0] = i + 1;
	j[1] = i + 2;
	j[2] = i + 3;
	j[3] = i;
	if (a[j[0]] < a[i] && a[j[0]] < a[j[1]] && a[j[0]] < a[j[2]])
		swap(&a[i], &a[j[0]], 'a');
	if (a[j[1]] < a[i] && a[j[1]] < a[j[0]] && a[j[1]] < a[j[2]])
		rrepeat(a, l, i, 2);
	if (a[j[2]] < a[i] && a[j[2]] < a[j[0]] && a[j[2]] < a[j[1]])
		rrot(a, l, i, 'a');
	while (a[j[3]] < a[j[3] + 1] && j[3] < l - 1)
		if (j[3]++ == (l - 2))
			return ;
	write(1, "pb\n", 3);
	three(a, l, i + 1);
	write(1, "pa\n", 3);
}

void	five(int *a, int l, int i)
{
	int	b;
	int	c;
	int	d;
	int	e;
	int	f;

	b = i + 1;
	c = i + 2;
	d = i + 3;
	e = i + 4;
	f = i;
	if (a[b] < a[i] && a[b] < a[c] && a[b] < a[d] && a[b] < a[e])
		swap(&a[i], &a[b], 'a');
	if (a[c] < a[i] && a[c] < a[b] && a[c] < a[d] && a[c] < a[e])
		repeat(a, l, i, 2);
	if (a[d] < a[i] && a[d] < a[b] && a[d] < a[c] && a[d] < a[e])
		rrepeat(a, l, i, 2);
	if (a[e] < a[i] && a[e] < a[b] && a[e] < a[c] && a[e] < a[d])
		rrot(a, l, i, 'a');
	while (a[f] < a[f + 1] && f < l - 1)
		if (f++ == (l - 2))
			return ;
	write(1, "pb\n", 3);
	four(a, l, i + 1);
	write(1, "pa\n", 3);
}
