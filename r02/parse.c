/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 00:50:36 by mhuron            #+#    #+#             */
/*   Updated: 2025/02/02 01:02:10 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "load_dict.h"
#include "ft_split.h"

typedef struct s_dict
{
	char	*number;
	char	*letters;
}	t_dict;

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (*str != '\0')
	{
		size++;
		str++;
	}
	return (size);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	if (dest == NULL || src == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

s_dict	**parser(char *my_dict)
{
	char	*text_dict;
	s_dict	**parsed_dict;

	text_dict = full_dict(my_dict);
	//compter le nombre de :
	//ft split avec whitespace et :
	//boucle alloc mon ** s dict
	//free le ft_split
}
