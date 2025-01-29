/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:03:15 by mhuron            #+#    #+#             */
/*   Updated: 2025/01/28 19:51:23 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str[size] != '\0')
		size++;
	return (size);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		src_len;
	int		i;

	src_len = ft_strlen(src);
	dup = 0;
	i = 0;
	dup = malloc(src_len * sizeof(char));
	if (dup == 0)
		return (0);
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = src[i];
	return (dup);
}
