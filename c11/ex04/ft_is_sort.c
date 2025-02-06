/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:58:37 by mhuron            #+#    #+#             */
/*   Updated: 2025/02/06 18:11:38 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_sign(int a)
{
	if (a < 0)
		return (-1);
	if (a > 0)
		return (1);
	return (0);
}

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
		if (sign * ((*f)(tab[i - 1], tab[i])) < 0)
			return (0);
		if ((*f)(tab[i - 1], tab[i]) != 0)
			sign = get_sign((*f)(tab[i - 1], tab[i]));
		i++;
	}
	return (1);
}
