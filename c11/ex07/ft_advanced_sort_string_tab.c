/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:16:26 by mhuron            #+#    #+#             */
/*   Updated: 2025/02/06 18:06:52 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = 0;
	while (tab[size] != (void *)0)
		size++;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if ((*cmp)(tab[i], tab[j]) > 0)
				ft_swap(tab + i, tab + j);
			j++;
		}
		i++;
	}
}
