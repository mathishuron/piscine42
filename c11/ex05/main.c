/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:43:42 by mhuron            #+#    #+#             */
/*   Updated: 2025/02/05 22:12:47 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);
int		ft_atoi(char *str);
int		add(int a, int b);
int		sub(int a, int b);
int		mult(int a, int b);
int		div(int a, int b);
int		mod(int a, int b);

void	ft_putstr(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}

int	(*pos(char c))(int, int)
{
	char	*op;
	int		i;
	int		(*f[5])(int, int);

	f[0] = &add;
	f[1] = &sub;
	f[2] = &mult;
	f[3] = &div;
	f[4] = &mod;
	op = "+-*/%";
	i = 0;
	while (i < 5)
	{
		if (c == op[i])
			return (f[i]);
		i++;
	}
	return ((void *)0);
}

int	main(int argc, char **argv)
{
	int	a;
	int	b;
	int	(*f)(int, int);

	if (argc == 4)
	{
		f = pos(argv[2][0]);
		a = ft_atoi(argv[1]);
		b = ft_atoi(argv[3]);
		if (f == (void *)0)
		{
			ft_putnbr(0);
			ft_putstr("\n");
		}
		else if (f == &div && b == 0)
			ft_putstr("Stop : division by zero\n");
		else if (f == &mod && b == 0)
			ft_putstr("Stop : modulo by zero\n");
		else
		{
			ft_putnbr(f(a, b));
			ft_putstr("\n");
		}
	}
	return (0);
}
