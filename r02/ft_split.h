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

int		is_in(char c, char *str);
char	**my_copy(char **dst, char *str, int *i, int *j);
int		nb_m(char *str, char *charset);
char	**ft_split(char *str, char *charset);

#endif
