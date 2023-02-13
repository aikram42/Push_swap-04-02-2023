/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:02:19 by aikram            #+#    #+#             */
/*   Updated: 2023/02/03 22:51:03 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t  i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	chkr_dup(int *i, t_ps *ps)
{
	i[2] = 0;
	while (++i[1] < (i[0] - 1))
	{
		i[2] = i[1];
		while (++i[2] < i[0] - 1)
			if (ps->ints[i[1]] == ps->ints[i[2]])
				freep(ps, ERR_DUP);
	}
}

void	freep(t_ps *ps, char *err)
{
	if (ps->ints)
		free (ps->ints);
	if (ps->stb)
		free (ps->stb);
	if (ps->sta)
		free (ps->sta);
	if (err)
	{
		write(2, err, ft_strlen(err));
		exit(1);
	}
}
