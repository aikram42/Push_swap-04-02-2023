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

int	*ac2(char **av, char **s, int *ints)
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
			ints[++i[1]] = ft_atoi(s[i[2]]);
			if (ft_not_atoi(s[i[2]]))
			{
				while (s[i[2]])
					free(s[i[2]++]);
				free(s);
				free(ints);
				return (0);
			}
			free(s[i[2]]);
		}
		free(s);
	}
	return (ints);
}

int	amt(char **av)
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

// void	chk_solved(int *num, int l)
// {
// 	if (num )
// }

int	main(int ac, char **av)
{
	char	**str;
	int		i[4];
	t_ps	ps;

	if (ac > 2)
	{
		i[1] = -1;
		i[0] = amt(av);
		ps.stb = NULL;
		ps.sta = NULL;
		str = NULL;
		ps.ints = malloc(sizeof(int) * i[0]);
		if (!ps.ints)
			return (1);
		ps.ints = ac2(av, str, ps.ints);
		chkr_dup(i, &ps);
		push_swap(&ps, i[0]);
		freep(&ps, NULL);
		return (0);
	}
	write (2, "Error: Invalid arguments\n", 25);
	return (1);
}
