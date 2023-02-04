/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:31:28 by aikram            #+#    #+#             */
/*   Updated: 2023/02/03 20:41:17 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(int *a, int *b, char ab)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
	if (ab == 'a')
		write(1, "sa\n", 3);
	else if (ab == 'b')
		write(1, "sb\n", 3);
}

void	rrot(int *a, int l, int start, char ab)
{
	int	i;
	int	t;
	int	p;

	i = start;
	t = a[start];
	while (++i < l)
	{
		p = a[i];
		a[i] = t;
		t = p;
	}
	a[start] = t;
	if (ab == 'a')
		write(1, "rra\n", 4);
	if (ab == 'b')
		write(1, "rrb\n", 4);
}

void	rot(int *a, int l, int start, char ab)
{
	int	t;
	int	p;
	int	i;

	i = l;
	t = a[i - 1];
	while (start < --i)
	{
		p = a[i - 1];
		a[i - 1] = t;
		t = p;
	}
	a[l - 1] = t;
	if (ab == 'a')
		write(1, "ra\n", 3);
	if (ab == 'b')
		write(1, "rb\n", 3);
}

void	repeat(int *a, int l, int s, int r)
{
	int	i;

	i = -1;
	while (++i < r)
		rot(a, l, s, 'a');
}

void	rrepeat(int *a, int l, int s, int rr)
{
	int	i;

	i = -1;
	while (++i < rr)
		rrot(a, l, s, 'a');
}
