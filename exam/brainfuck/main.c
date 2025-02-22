/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:38:58 by mhuron            #+#    #+#             */
/*   Updated: 2025/02/22 21:15:19 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "util.h"

int	main(int argc, char *argv[])
{
	int		pointed_byte;
	int		i;
	char	my_array_code[2048];
	int		count_nested;

	pointed_byte = 0;
	i = 0;
	if (argc == 2)
	{
		while (pointed_byte < 2048)
			my_array_code[pointed_byte++] = 0;
		pointed_byte = 0;
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] == '>')
				pointed_byte++;
			else if (argv[1][i] == '<')
				pointed_byte--;
			else if (argv[1][i] == '+')
				my_array_code[pointed_byte] += 1;
			else if (argv[1][i] == '-')
				my_array_code[pointed_byte] -= 1;
			else if (argv[1][i] == '.')
				ft_putchar(my_array_code[pointed_byte]);
			else if (argv[1][i] == '[')
			{
				if (my_array_code[pointed_byte] == 0)
				{
					count_nested = 0;
					i++;
					while (argv[1][i] != ']' || count_nested != 0)
					{
						if (argv[1][i] == '[')
							count_nested++;
						if (argv[1][i] == ']')
							count_nested--;
						i++;
					}
				}
			}
			else if (argv[1][i] == ']')
			{
				if (my_array_code[pointed_byte] != 0)
				{
					count_nested = 0;
					i--;
					while (argv[1][i] != '[' || count_nested != 0)
					{
						if (argv[1][i] == ']')
							count_nested++;
						if (argv[1][i] == '[')
							count_nested--;
						i--;
					}
				}
			}
			i++;
		}
	}
	else
		ft_putstr("\n");
	return (0);
}
