/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 00:50:36 by mhuron            #+#    #+#             */
/*   Updated: 2025/02/02 13:47:03 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "load_dict.h"
#include "ft_split.h"
#include "translate.h"

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

int	occ_char(char *str, char c)
{
	int	occ;

	occ = 0;
	while (*str != '\0')
	{
		if (*str == c)
			occ++;
		str++;
	}
	return (occ);
}

t_dict	*parser(char *dict_name)
{
	char	*text_dict;
	t_dict	*parsed_dict;

	text_dict = full_dict(dict_name);
	parsed_dict = ft_split(text_dict, occ_char(text_dict, ':'));
	free(text_dict);
	return (parsed_dict);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc > 1)
		translate(argv[1]);
	return (0);
}
