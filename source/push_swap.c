/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 09:20:26 by aikram            #+#    #+#             */
/*   Updated: 2023/02/03 22:49:23 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_ps *ps, int l)
{
	if (l == 2)
		two(ps->ints);
	else if (l == 3)
		three(ps->ints, l, 0);
	else if (l == 4)
		four(ps->ints, l, 0);
	else if (l == 5)
		five(ps->ints, l, 0);
	else
		big_boi(ps, l);
}

void	av_absorber(char **av, char **s, t_ps *ps)
{
	int		i[4];

	i[0] = 0;
	i[1] = -1;
	i[3] = 0;
	while (av[++i[3]])
	{
		i[2] = -1;
		s = ft_split(av[i[3]], ' ');
		while (s[++i[2]])
		{
			ps->ints[++i[1]] = giga_chad_atoi(s[i[2]], ps);
			if (ps->bad_no)
			{
				while (s[i[2]])
					free(s[i[2]++]);
				free(s);
				freep(ps, ERR_ARG);
			}
			free(s[i[2]]);
		}
		free(s);
	}
	return ;
}

int	arr_len(char **av)
{
	int	i;
	int	l;
	int	j;

	i = 0;
	j = 0;
	while (av[++i])
	{
		l = -1;
		while (av[i][++l])
		{
			if (l == 0 && av[i][l] != ' ' && av[i][l])
				j++;
			if (av[i][l] == ' ' && av[i][l + 1] != ' '
				&& av[i][l + 1])
				j++;
		}
	}
	return (j);
}

void	chk_sol(t_ps *ps, int l)
{
	int	i;

	i = -1;
	while (++i < l - 1)
	{
		if (ps->ints[i] >= ps->ints[i + 1])
			return ;
	}
	write(1, BRUH, 29);
	free(ps->ints);
	exit(0);
	
}

int	main(int ac, char **av)
{
	char	**str;
	int		i[4];
	t_ps	ps;

	if (ac > 2)
	{
		
		i[1] = -1;
		i[0] = arr_len(av);
		ps.stb = NULL;
		ps.sta = NULL;
		str = NULL;
		ps.ints = malloc(sizeof(int) * i[0]);
		if (!ps.ints)
			return (1);
		av_absorber(av, str, &ps);
		chkr_dup(i, &ps);
		chk_sol(&ps, i[0]);
		push_swap(&ps, i[0]);
		freep(&ps, NULL);
		return (0);
	}
	write (2, INV_ARG, 25);
	return (1);
}
