/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:09:05 by mhuron            #+#    #+#             */
/*   Updated: 2025/02/02 00:50:10 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPLIT_H
# define FT_SPLIT_H

typedef struct s_dict
{
	char	*number;
	char	*letters;
}	t_dict;

int		is_in(char c);
int		my_copy_nb(t_dict *dst, char *str);
int		my_copy_lt(t_dict *dst, char *str, int *curr);
t_dict	*ft_split(char *str, int size);

#endif
