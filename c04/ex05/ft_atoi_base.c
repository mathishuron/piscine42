/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:40:01 by mhuron            #+#    #+#             */
/*   Updated: 2025/01/23 18:25:33 by mhuron           ###   ########.fr       */
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

int	ft_base_position(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || ft_isspace(base[i]) == 1)
			return (0);
		while (base[j] != '\0')
		{
			if (i != j && base[i] == base[j])
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	neg_count;
	int	i;
	int	result;

	neg_count = 0;
	i = 0;
	result = 0;
	if (check_base(base) == 0)
		return (0);
	while (ft_isspace(str[i]) == 1 && str[i] != '\0')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg_count++;
		i++;
	}
	while (ft_base_position(str[i], base) >= 0)
	{
		result *= ft_strlen(base);
		result -= ft_base_position(str[i], base);
		i++;
	}
	return (result * (2 * (neg_count % 2) - 1));
}
