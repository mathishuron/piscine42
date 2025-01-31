/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:39:27 by mhuron            #+#    #+#             */
/*   Updated: 2025/01/31 11:29:54 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = min;
	if (range == NULL)
		return (-1);
	*range = NULL;
	if (max <= min)
		return (0);
	*range = malloc((max - min) * sizeof(int));
	if (*range == NULL)
		return (-1);
	while (i < max)
	{
		(*range)[i - min] = i;
		i++;
	}
	return (max - min);
}
