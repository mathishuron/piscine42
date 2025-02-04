/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:40:01 by mhuron            #+#    #+#             */
/*   Updated: 2025/02/04 17:59:38 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v')
	{
		return (1);
	}
	return (0);
}

int	ft_is_numeric(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	i;
	int	result;

	sign = -1;
	i = 0;
	result = 0;
	while (ft_isspace(str[i]) == 1 && str[i] != '\0')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_is_numeric(str[i]) == 1)
	{
		result *= 10;
		result -= (str[i] - '0');
		i++;
	}
	return (sign * result);
}
