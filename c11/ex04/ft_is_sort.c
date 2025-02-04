/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:58:37 by mhuron            #+#    #+#             */
/*   Updated: 2025/02/04 17:38:27 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	sign;

	i = 1;
	sign = 0;
	if (length <= 2)
		return (1);
	while (i < length)
	{
		if (sign * (f(tab[i - 1], tab[i])) < 0)
			return (0);
		if (f(tab[i - 1], tab[i]) != 0)
			sign = f(tab[i - 1], tab[i]);
		i++;
	}
	return (1);
}
