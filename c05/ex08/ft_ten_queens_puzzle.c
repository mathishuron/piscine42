/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:51:17 by mhuron            #+#    #+#             */
/*   Updated: 2025/02/10 20:00:10 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}

int	abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	is_valid(char *q, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (q[j] == q[i] || abs(q[j] - q[i]) == i - j)
			return (0);
		j++;
	}
	return (1);
}

void	place_next_queen(char *queens, int i, int *nb)
{
	int	pos;

	pos = '0';
	if (i > 9)
	{
		ft_putstr(queens);
		ft_putstr("\n");
		*nb += 1;
		return ;
	}
	while (pos <= '9')
	{
		queens[i] = pos;
		if (is_valid(queens, i) == 1)
			place_next_queen(queens, i + 1, nb);
		pos++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	queens[11];
	int		number_of_sol;

	number_of_sol = 0;
	queens[10] = '\0';
	place_next_queen(queens, 0, &number_of_sol);
	return (number_of_sol);
}
