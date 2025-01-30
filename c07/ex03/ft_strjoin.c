/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:54:52 by mhuron            #+#    #+#             */
/*   Updated: 2025/01/30 15:27:53 by mhuron           ###   ########.fr       */
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

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	total_size(int size, char **strs, char *sep)
{
	int	i;
	int	taille_totale;

	i = 0;
	taille_totale = 0;
	while (i < size)
	{
		taille_totale += ft_strlen(strs[i]);
		if (i < size - 1)
			taille_totale += ft_strlen(sep);
		i++;
	}
	return (taille_totale);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*cat;
	int		taille_totale;
	int		i;
	int		j;
	int		arg_count;

	cat = NULL;
	taille_totale = total_size(size, strs, sep);
	i = 0;
	arg_count = 0;
	cat = (char *)malloc((taille_totale + 1) * sizeof(char));
	if (cat == NULL)
		return (cat);
	while (i < taille_totale)
	{
		j = 0;
		while (strs[arg_count][j] != '\0')
			cat[i++] = strs[arg_count][j++];
		arg_count++;
		j = 0;
		while (sep[j] != '\0' && arg_count < size)
			cat[i++] = sep[j++];
	}
	cat[i] = '\0';
	return (cat);
}
