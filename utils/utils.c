/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 11:30:22 by aikram            #+#    #+#             */
/*   Updated: 2023/02/03 23:38:38 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_spit(char const *s, char c, char **strr, int *i)
{
	while (++i[2] < i[1])
	{
		i[4] = 0;
		i[5] = -1;
		while (s[++i[3]] == c && s[i[3]])
			;
		while (s[i[3]] != c && s[i[3]])
		{
			i[4]++;
			i[3]++;
		}
		strr[i[2]] = (char *)malloc(sizeof(*strr[i[2]]) * (i[4] + 1));
		i[3] -= i[4];
		while (s[i[3]] != c && s[i[3]])
		{
			strr[i[2]][++i[5]] = s[i[3]];
			i[3]++;
		}
		strr[i[2]][++i[5]] = '\0';
	}
	strr[i[2]] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**strr;
	int		i[6];
	int		j;

	if (!s)
		return (0);
	j = -1;
	while (++j < 6)
		i[j] = -1;
	i[1] = 0;
	while (s[++i[0]])
	{
		if (i[0] == 0 && s[i[0]] != c && s[i[0]])
			i[1]++;
		if (s[i[0]] == c && s[i[0] + 1] != c && s[i[0] + 1])
			i[1]++;
	}
	strr = (char **)malloc(sizeof(*strr) * (i[1] + 1));
	if (!strr)
		return (0);
	ft_spit(s, c, strr, i);
	return (strr);
}

unsigned long long chk_len(unsigned long long num)
{
	 unsigned long long i;

	 i = 0;
	 while (num)
	 {
		num /= 10;
		i++;
	 }
	 return (i);
}

int	giga_chad_atoi(char *str, t_ps *ps)
{
		unsigned long long	r;
		unsigned long long	i;
		int					s;
		
		s = 1;
		i = 0;
		r = 0;
		ps->bad_no = 1;
		while (*str == 32 || (*str >= 9 && *str <= 13))
			str++;
		if (str[i] == '-' || str[i] == '+')
			if (str[i++] == '-')
				s *= -1;
		while (str[i] >= '0' && str[i] <= '9')
			r = r * 10 + str[i++] - '0';
		if ((r > 2147483647 && s == 1) ||(r > 2147483648 && s == -1) || str[i]
			|| chk_len(r) != i)
			return (1);
		ps->bad_no = 0;
		return (r * s);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*str;

	i = 0;
	str = malloc(count * size);
	if (!str)
		return (0);
	while (i < (count * size))
		((char *)str)[i++] = '\0';
	return (str);
}
