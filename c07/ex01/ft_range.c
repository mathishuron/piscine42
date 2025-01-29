/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:39:27 by mhuron            #+#    #+#             */
/*   Updated: 2025/01/28 19:51:47 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*my_array;
	int	i;

	my_array = NULL;
	i = min;
	if (max <= min)
		return (NULL);
	my_array = malloc((max - min) * sizeof(int));
	if (my_array == NULL)
		return (my_array);
	while (i < max)
	{
		my_array[i - min] = i;
		i++;
	}
	return (my_array);
}
