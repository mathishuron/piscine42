/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:18:47 by mhuron            #+#    #+#             */
/*   Updated: 2025/01/23 18:42:39 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	display_number(int n, char *base)
{
	write(1, &base[-1 * n], 1);
}

void	recursive_display(int n, int base_len, char *base)
{
	if (n <= -base_len)
	{
		recursive_display(n / base_len, base_len, base);
	}
	display_number(n % base_len, base);
}

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (*str != '\0')
	{
		size++;
		str++;
	}
	return (size);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| base[i] == '\f' || base[i] == '\n' || base[i] == '\r'
			|| base[i] == '\t' || base[i] == '\v')
			return (0);
		while (base[j] != '\0')
		{
			if (i != j && base[i] == base[j])
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (check_base(base) == 0)
		return ;
	if (nbr < 0)
		write(1, "-", 1);
	if (nbr > 0)
		nbr = nbr * -1;
	recursive_display(nbr, base_len, base);
}
