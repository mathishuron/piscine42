/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 23:51:52 by mhuron            #+#    #+#             */
/*   Updated: 2025/02/02 00:43:25 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	size_dict(char *my_dict)
{
	char	buffer[16];
	int		size;
	int		fd;
	int		size_read;

	size = 0;
	fd = open(my_dict, O_RDONLY);
	if (fd == -1)
		return (0);
	while (1)
	{
		size_read = read(fd, buffer, 16);
		if (size_read == 0)
			break ;
		size += size_read;
	}
	close(fd);
	return (size);
}

char	*full_dict(char *my_dict)
{
	char	*buffer;
	int		fd;
	int		size;

	size = size_dict(my_dict);
	fd = open(my_dict, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buffer = (char *)malloc((size + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	read(fd, buffer, size_dict(my_dict));
	buffer[size] = '\0';
	close(fd);
	return (buffer);
}
