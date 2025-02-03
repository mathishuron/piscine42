/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:41:33 by mhuron            #+#    #+#             */
/*   Updated: 2025/02/01 17:07:47 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

typedef struct s_number
{
	char	*value;
	char	*writing;
}	t_number;

char	*read_file(char *my_dict)
{
	int	read_size;
	int	count;
	char	buf[16];
	char	*res;

	read_size = 0;
	count = 0;
	int fd = open(my_dict, O_RDONLY);
	if (fd < 0)
		return (0);
	while (1)
	{
		read_size = read(fd, buf, 16);
		count += read_size;
		if (read_size <= 0)
			break ;
	}
	close(fd);
	res = malloc(count + 1);
	fd = open(my_dict, O_RDONLY);
	read(fd, res, count);
	res[count] = 0;
	close(fd);
	return (res);
}

// t_number	*parse_dict(char *my_dict)
// {
// 	char	buf[16];
// 	int	read_size;
// 	t_number	**parsed_dict;
// 	int	i;
// 	int	j;
// 
// 	i = 0;
// 	read_size = 0;
// 	int fd = open(my_dict, O_RDONLY);
// 	if (fd < 0)
// 		return (NULL);
// 	parsed_dict = malloc(sizeof(t_number *) * (count_dict(my_dict) + 1));
// 	while (1)
// 	{
// 		j = 0;
// 		read_size = read(fd, buf, 16);
// 		if (read_size == 0)
// 			break ;
// 		while (i < count_dict(my_dict))
// 		{
// 			parsed_dict[i]->
// 	}
// 	close(file);
// 	return (t_number;
// }

#include <stdio.h>

int	main(int argc, char *argv[])
{
	printf("%s", read_file(argv[1]));
}
