/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatihsoymaz <fatihsoymaz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:36:44 by fatihsoymaz       #+#    #+#             */
/*   Updated: 2023/01/20 14:30:14 by fatihsoymaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
int		ft_fnl(char *str);
char	*ft_strjoin(char *str, char	*buffer);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*after_next_line(char *holder);
char	*till_next_line(char	*holder);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
#endif
