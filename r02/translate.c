/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:26:17 by mhuron            #+#    #+#             */
/*   Updated: 2025/02/02 16:13:37 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_split.h"
#include "load_dict.h"
#include "translate.h"
#include "parse.h"

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void	my_free(t_dict *parsed)
{
	int	i;
	
	i = 0;
	while (parsed[i].number != NULL)
	{
		free(parsed[i].number);
		free(parsed[i].letters);
		i++;
	}
	free(parsed);
}

void	ft_put(t_dict *dict, char *nbr, int pow, int *pos)
{
	int	i;

	i = 0;
	
	if ((pow % 3) == 2 && nbr[0] == '1')
	{
		while (dict[i].number != NULL)
		{
			if (nbr[0] == dict[i].number[0] \
			&& nbr[1] == dict[i].number[1] && dict[i].pow == 2)
			{
				ft_putstr(dict[i].letters);
				ft_putstr(" ");
			}
			i++;
		}
		*pos += 1;
	}
	else if ((pow % 3) == 2)
	{
		while (dict[i].number != NULL)
		{
			if (nbr[0] == dict[i].number[0] && dict[i].pow == 2)
			{
				ft_putstr(dict[i].letters);
				ft_putstr(" ");
			}
			i++;
		}
	}
	else
	{
                while (dict[i].number != NULL)
                {
                        if (nbr[0] == dict[i].number[0] && dict[i].pow == 1)
                        {
                                ft_putstr(dict[i].letters);
                                ft_putstr(" ");
                        }
                        i++;
                }
	}
}

void	translate(char *str)
{
	int		i;
	int		j;
	int		size;
	t_dict	*parsed;

	i = 0;
	size = ft_strlen(str);
	parsed = parser("numbers.dict");
	while (str[i] != 0)
	{
		ft_put(parsed, str + i, size - i, &i);
		if ((size - i) % 3 == 0)
		{
			j = 0;
			while (parsed[j].number != NULL)
			{
				if (parsed[j].pow == 3)
				{
					ft_putstr(parsed[j].letters);
					ft_putstr(" ");
				}
			j++;
			}
		}
		i++;
	}
	ft_putstr("\n");
	my_free(parsed);
}
