/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:53:15 by mhuron            #+#    #+#             */
/*   Updated: 2025/01/31 11:30:55 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	check_base(char *base);
int	ft_strlen(char *str);

void	recursive_alloc(int n, int *i, char *result, char *base)
{
	if (n <= -ft_strlen(base))
	{
		recursive_alloc(n / ft_strlen(base), i, result, base);
		*i += 1;
	}
	result[*i] = base[-1 * (n % ft_strlen(base))];
	result[*i + 1] = '\0';
}

int	taille_nb(int nb, char *base)
{
	int	size;

	size = 1;
	if (nb < 0)
		size++;
	else
		nb = -nb;
	while (nb <= -ft_strlen(base))
	{
		nb = nb / ft_strlen(base);
		size++;
	}
	return (size);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*nbr_base;
	int		nbr_10;
	int		i;

	i = 0;
	nbr_base = NULL;
	if (check_base(base_from) == 0 || check_base(base_to) == 0)
		return (NULL);
	nbr_10 = ft_atoi_base(nbr, base_from);
	nbr_base = (char *)malloc((taille_nb(nbr_10, base_to) + 1) * sizeof(char));
	if (nbr_base == 0)
		return (NULL);
	if (nbr_10 < 0)
	{
		i++;
		nbr_base[0] = '-';
		recursive_alloc(nbr_10, &i, nbr_base, base_to);
	}
	else
		recursive_alloc(-nbr_10, &i, nbr_base, base_to);
	return (nbr_base);
}
