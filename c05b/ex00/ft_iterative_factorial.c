/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:26:31 by mhuron            #+#    #+#             */
/*   Updated: 2025/01/28 15:11:44 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	resultat;
	int	i;

	resultat = 1;
	i = 1;
	if (nb < 0)
		return (0);
	while (i <= nb)
	{
		resultat *= i;
		i++;
	}
	return (resultat);
}
