/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:09:05 by mhuron            #+#    #+#             */
/*   Updated: 2025/01/29 16:38:48 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_in(char c, char *str)
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

void	my_copy(char *dst, char *str, int *i, int *j)
{
	int	k;

	dst = (char *)malloc((*j + 1) * sizeof(char));
	k = 0;
	while (k < *j)
	{
		dst[k] = str[*i + k];
		k++;
	}
	dst[k] = '\0';
	*i += *j;
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
		if (ft_is_in(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (ft_is_in(str[i + j], charset) == 0)
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
	result = (char **)malloc(nb_m(str, charset) * sizeof(char *));
	while (str[i] != '\0')
	{
		if (ft_is_in(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (ft_is_in(str[i + j], charset) == 0)
				j++;
			my_copy(result[nb_mots], str, &i, &j);
			nb_mots++;
		}
	}
	result[nb_mots] = (char *)malloc(sizeof(char));
	result[nb_mots][0] = '\0';
	return (result);
}

#include <stdio.h>
int	main(void)
{
	int i = 0;
	char **c = ft_split("bonjour je-suis  b-- --eau","- ");
	while(c[i][0] != '\0')
	{
		printf("%s\n", c[i]);
		i++;
	}
	free(c);
}
