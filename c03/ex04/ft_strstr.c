/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:22:02 by mhuron            #+#    #+#             */
/*   Updated: 2025/01/23 12:46:52 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				diff;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		diff = s1[i] - s2[i];
		if (diff != 0)
		{
			return (diff);
		}
		i++;
	}
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
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

char	*ft_strstr(char *str, char *to_find)
{
	int	size_to_find;
	int	i;

	size_to_find = ft_strlen(to_find);
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_strncmp(str + i, to_find, size_to_find) == 0)
		{
			return (str + i);
		}
		i++;
	}
	return (0);
}
