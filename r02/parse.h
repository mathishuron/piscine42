/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhuron <mhuron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:52:22 by mhuron            #+#    #+#             */
/*   Updated: 2025/02/02 13:54:06 by mhuron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

int	ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
int	occ_char(char *str, char c);
t_dict	*parser(char *dict_name);

#endif
