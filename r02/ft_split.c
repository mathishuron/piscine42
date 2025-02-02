/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:09:05 by mhuron            #+#    #+#             */
/*   Updated: 2025/02/01 22:56:07 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_split.h"

int	is_in(char c)
{
	int		i;
	char	*str;

	str = " :\n";
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	my_copy_nb(t_dict *dst, char *str)
{
	int	k;
	int	j;

	k = 0;
	j = 0;
	while (is_in(str[j]) == 0 && str[j])
		j++;
	(*dst).number = (char *)malloc((j + 1) * sizeof(char));
	if (!(*dst).number)
		return (0);
	while (k < j)
	{
		(*dst).number[k] = str[k];
		k++;
	}
	(*dst).number[k] = '\0';
	return (k);
}

int	my_copy_lt(t_dict *dst, char *str, int	*curr)
{
	int	k;
	int	j;

	k = 0;
	j = 0;
	while (is_in(str[j]) == 0 && str[j])
		j++;
	(*dst).letters = (char *)malloc((j + 1) * sizeof(char));
	if (!(*dst).letters)
		return (0);
	while (k < j)
	{
		(*dst).letters[k] = str[k];
		k++;
	}
	(*dst).letters[k] = '\0';
	*curr += 1;
	return (k);
}

t_dict	*ft_split(char *str, int size)
{
	t_dict	*result;
	int		i;
	int		cw;
	int		flag;

	cw = 0;
	i = 0;
	flag = 0;
	result = (t_dict *)malloc((size + 1) * sizeof(t_dict));
	if (!result)
		return (NULL);
	while (str[i] != '\0')
	{
		if (is_in(str[i]) == 0)
		{
			if (flag == 0)
				i += my_copy_nb(&result[cw], str + i);
			if (flag == 1)
				i += my_copy_lt(&result[cw], str + i, &cw);
			flag = 1 - flag;
		}
		else
			i++;
	}
	result[cw].number = NULL;
	return (result);
}
