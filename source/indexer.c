/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortin_v2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 15:11:07 by aikram            #+#    #+#             */
/*   Updated: 2022/05/17 17:30:16 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	dp_one(t_ps *ps, int l)
{
	int	i;

	i = -1;
	while (++i < l)
	{
		if (!i)
		{
			ps->ph = ps->ints[i];
			ps->p = i;
		}
		else if (ps->ints[i] < ps->ph)
		{
			ps->ph = ps->ints[i];
			ps->p = i;
		}
	}
	ps->sta[ps->p] = 0;
}

void	dp_two(t_ps *ps, int l)
{
	int	i;

	i = -1;
	while (++i < l)
	{
		if (ps->ph < ps->ints[i])
		{
			ps->ph = ps->ints[i];
			ps->p = i;
			return ;
		}
	}
}

void	indexer(t_ps *ps, int l)
{
	int	i;
	int	j;

	i = 0;
	ps->sta = (int *)malloc(l * sizeof(int));
	dp_one(ps, l);
	while (++i < l)
	{
		ps->prh = ps->ph;
		dp_two(ps, l);
		j = -1;
		while (++j < l)
		{
			if (ps->ph > ps->ints[j] && ps->ints[j] > ps->prh)
			{
				ps->ph = ps->ints[j];
				ps->p = j;
			}
		}
		ps->sta[ps->p] = i;
	}
}
