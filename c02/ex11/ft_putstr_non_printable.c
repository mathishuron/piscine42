/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:00:51 by mhuron            #+#    #+#             */
/*   Updated: 2025/01/21 16:18:44 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_printable(char c)
{
	if (c < 32 || c >= 126)
	{
		return (0);
	}
	return (1);
}

int	inttohex(int c)
{
	if (c > 9)
	{
		return (c - 10 + 'a');
	}
	else
	{
		return (c + '0');
	}
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	int		first_char;
	int		last_char;
	char	backslash;

	backslash = '\\';
	i = 0;
	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
		{
			write(1, str + i, 1);
		}
		else
		{
			write(1, &backslash, 1);
			first_char = str[i] / 16 + '0';
			write(1, &first_char, 1);
			last_char = inttohex(str[i] % 16);
			write(1, &last_char, 1);
		}
		i++;
	}
}
