/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:35:55 by mhuron            #+#    #+#             */
/*   Updated: 2025/01/16 15:22:16 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	display_number(int n)
{
	int	number_ascii;

	number_ascii = n + 48;
	write(1, &number_ascii, 1);
}

void	recursive_display(int n)
{
	if (n >= 1)
	{
		recursive_display(n / 10);
		display_number(n % 10);
	}
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
	}
	recursive_display(nb);
}
