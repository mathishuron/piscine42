/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:20:57 by mhuron            #+#    #+#             */
/*   Updated: 2025/01/16 15:21:46 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	translation(int i, int j)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = i % 10 + 48;
	b = i / 10 + 48;
	c = j % 10 + 48;
	d = j / 10 + 48;
	write(1, &b, 1);
	write(1, &a, 1);
	write(1, " ", 1);
	write(1, &d, 1);
	write(1, &c, 1);
	if (!(i == 98 && j == 99))
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i <= 98)
	{
		while (j <= 99)
		{
			if (i < j)
			{
				translation(i, j);
			}
		j++;
		}
	i++;
	j = 1;
	}
}
