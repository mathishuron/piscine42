/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:27:50 by mhuron            #+#    #+#             */
/*   Updated: 2025/01/20 17:57:53 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int     is_printable(char c)
{
	if (c < ' ' || c > '~')
	{
		return (0);
	}
	return (1);
}

void	display_number(int n)
{
	int	number_ascii;
	if (n > 9)
	{
		number_ascii = (n - 10 + 'a');
	}
	else
	{
	  	number_ascii = (n + '0');
	}
	write(1, &number_ascii, 1);
}

void	recursive_display(int n, int limit)
{
	if (limit>0)
	{
		recursive_display(n / 16, limit - 1);
		display_number(n % 16);
	}
}

void	memzone(void *addr)
{
	recursive_display(addr, 16);
}
#include <stdio.h>
int	main(void)
{
	char c[] = "Coucou";
	memzone(c);
	return (0);
}
