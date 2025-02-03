/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:09:05 by mhuron            #+#    #+#             */
/*   Updated: 2025/02/03 12:37:30 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_in(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	**my_copy(char **dst, char *str, int *i, int *j)
{
	int	k;

	*dst = NULL;
	*dst = (char *)malloc((*j + 1) * sizeof(char));
	if (!*dst)
		return (NULL);
	k = 0;
	while (k < *j)
	{
		(*dst)[k] = str[*i + k];
		k++;
	}
	(*dst)[k] = '\0';
	*i += *j;
	return (dst);
}

int	nb_m(char *str, char *charset)
{
	int	i;
	int	j;
	int	nb_mots;

	i = 0;
	nb_mots = 0;
	while (str[i] != '\0')
	{
		if (is_in(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (str[i + j] && is_in(str[i + j], charset) == 0)
				j++;
			i += j;
			nb_mots++;
		}
	}
	return (nb_mots);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		j;
	int		nb_mots;

	nb_mots = 0;
	i = 0;
	result = (char **)malloc((nb_m(str, charset) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (str[i] != '\0')
	{
		if (is_in(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (str[i + j] && is_in(str[i + j], charset) == 0)
				j++;
			my_copy(result + nb_mots++, str, &i, &j);
		}
	}
	result[nb_mots] = NULL;
	return (result);
}
