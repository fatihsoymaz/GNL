/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsoymaz <fsoymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:36:44 by fatihsoymaz       #+#    #+#             */
/*   Updated: 2023/01/23 18:57:37 by fsoymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
int		ft_fnl(char *str);
char	*ft_strjoin(char *str, char	*buffer);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*next_line(char *str);
char	*read_line(char *str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
#endif
