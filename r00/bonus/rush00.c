/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:37:14 by maxmart2          #+#    #+#             */
/*   Updated: 2025/01/18 14:57:40 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_first_or_last_line(int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0 || i == x - 1)
			ft_putchar('o');
		else
			ft_putchar('-');
		i++;
	}
}

void	ft_print_middle_line(int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0 || i == x - 1)
			ft_putchar('|');
		else
			ft_putchar(' ');
		i++;
	}
}

void	rush(int x, int y)
{
	int	i;

	i = 0;
	if (x > 0 && y > 0)
	{
		while (i < y)
		{
			if (i == 0 || i == y - 1)
				ft_print_first_or_last_line(x);
			else
				ft_print_middle_line(x);
			ft_putchar('\n');
			i++;
		}
	}
}
