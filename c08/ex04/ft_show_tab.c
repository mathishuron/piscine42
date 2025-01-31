/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:38:14 by mhuron            #+#    #+#             */
/*   Updated: 2025/01/31 12:18:35 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void	display_number(int n)
{
	int	number_ascii;

	number_ascii = -n + '0';
	write(1, &number_ascii, 1);
}

void	recursive_display(int n)
{
	if (n <= -10)
	{
		recursive_display(n / 10);
	}
	display_number(n % 10);
}

void	ft_putnbr(int nbr)
{
	if (nbr < 0)
		write(1, "-", 1);
	if (nbr > 0)
		nbr = nbr * -1;
	recursive_display(nbr);
}


void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != NULL)
	{
		ft_putstr(par[i].str);
		ft_putstr("\n");
		ft_putnbr(par[i].size);
		ft_putstr("\n");
		ft_putstr(par[i].copy);
		ft_putstr("\n");
		i++;
	}
}
