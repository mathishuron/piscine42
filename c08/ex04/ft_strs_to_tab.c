/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:15:32 by mhuron            #+#    #+#             */
/*   Updated: 2025/01/31 12:30:12 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str[size] != '\0')
		size++;
	return (size);
}

char	*ft_strdup(char **src, int n)
{
	char	*dup;
	int		src_len;
	int		i;
	int		k;

	k = 0;
	src_len = ft_strlen(src[n]);
	dup = NULL;
	i = 0;
	dup = malloc((src_len + 1) * sizeof(char));
	if (dup == NULL)
	{
		while (k < n - 1)
		{
			free(src[k]);
			k++;
		}
		return (NULL);
	}
	while (src[n][i] != '\0')
	{
		dup[i] = src[n][i];
		i++;
	}
	dup[i] = src[n][i];
	return (dup);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int	i;
	t_stock_str	*str_array;
	
	i = 0;
	str_array = NULL;
	str_array = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (str_array == NULL)
		return (NULL);
	while (i < ac)
	{
		str_array[i].size = ft_strlen(av[i]);
		str_array[i].str = av[i];
		str_array[i].copy = ft_strdup(av, i);
		i++;
	}
	str_array[i].str = NULL;
	return (str_array);
}
