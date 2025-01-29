/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:23:02 by mhuron            #+#    #+#             */
/*   Updated: 2025/01/23 12:41:53 by mhuron           ###   ########.fr       */
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
