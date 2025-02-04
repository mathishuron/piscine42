/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:43:42 by mhuron            #+#    #+#             */
/*   Updated: 2025/02/04 17:54:14 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str);
void	ft_putnbr(int nb);

int	main(int argc, char **argv)
{
	int	a;
	int	b;

	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	if (argc == 4)
	{
		ft_putnbr(a);
	}
	return (0);
}
