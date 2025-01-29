/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:00:51 by mhuron            #+#    #+#             */
/*   Updated: 2025/01/21 17:57:19 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alpha(char c)
{
	if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
	{
		return (0);
	}
	return (1);
}

int	is_numeric(char c)
{
	if (c < '0' || c > '9')
	{
		return (0);
	}
	return (1);
}

void	upcase(char *str)
{
	if (*str >= 'a' && *str <= 'z')
	{
		*str -= 32;
	}
}

void	lowcase(char *str)
{
	if (*str >= 'A' && *str <= 'Z')
	{
		*str += 32;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	if (str[0] == '\0')
	{
		return (str);
	}
	upcase(str);
	while (str[i] != '\0')
	{
		if (is_alpha(str[i - 1]) == 0 && is_numeric(str[i - 1]) == 0)
		{
			upcase(str + i);
		}
		else if (is_alpha(str[i - 1]) == 1 || is_numeric(str[i - 1]) == 1)
		{
			lowcase(str + i);
		}
		i++;
	}
	return (str);
}
