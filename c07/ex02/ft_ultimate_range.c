/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:39:27 by mhuron            #+#    #+#             */
/*   Updated: 2025/01/28 19:52:44 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = min;
	if (max <= min)
		return (NULL);
	*range = malloc((max - min) * sizeof(int));
	if (!*range)
		return (NULL);
	while (i < max)
	{
		(*range)[i - min] = i;
		i++;
	}
	return (*range);
}
