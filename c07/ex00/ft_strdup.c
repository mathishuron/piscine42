/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:03:15 by mhuron            #+#    #+#             */
/*   Updated: 2025/01/31 11:29:26 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	if (str == NULL)
		return (0);
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
	dup = NULL;
	i = 0;
	if (src == NULL)
		return (NULL);
	dup = malloc((src_len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = src[i];
	return (dup);
}
