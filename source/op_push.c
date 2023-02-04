/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teleportin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:23:30 by aikram            #+#    #+#             */
/*   Updated: 2023/01/10 09:23:30 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_ps *ps)
{
	ps->a -= 1;
	ps->sta[ps->a] = ps->stb[ps->b];
	ps->b += 1;
	write(1, "pa\n", 3);
}

void	push_b(t_ps *ps)
{
	ps->b -= 1;
	ps->stb[ps->b] = ps->sta[ps->a];
	ps->a += 1;
	write(1, "pb\n", 3);
}
