/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:07:33 by mhuron            #+#    #+#             */
/*   Updated: 2025/02/04 18:00:36 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	recursive_display(int n)
{
	int	a;
	
	a = -(n % 10) + '0';
	if (n <= -10)
		recursive_display(n / 10);
	write(1, &a, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
		write(1, "-", 1);
	else
		nb = nb * -1;
	recursive_display(nb);
}
