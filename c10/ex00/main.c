/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:45:31 by mhuron            #+#    #+#             */
/*   Updated: 2025/02/06 15:13:48 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_puterr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, str + i, 1);
		i++;
	}
}

int	ft_display_file(char *name)
{
	int	fd;
	char	buf[16];
	int	read_size;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (1)
	{
		read_size = read(fd, buf, 16);
		if (read_size < 0)
			return (-1);
		if (read_size == 0)
			break ;
		write(1, buf, read_size);
	}
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	int	ret_val;

	if (argc < 2)
		ft_puterr("File name missing.\n");
	else if (argc > 2)
		ft_puterr("Too many arguments.\n");
	else
	{
		ret_val = ft_display_file(argv[1]);
		if (ret_val == -1)
			ft_puterr("Cannot read file.\n");
	}
	return (0);
}
