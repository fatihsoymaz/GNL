/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatihsoymaz <fatihsoymaz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:40:29 by fatihsoymaz       #+#    #+#             */
/*   Updated: 2023/01/20 14:43:20 by fatihsoymaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buffer;
	char		*result;
	int			count;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(buffer);
		return NULL;
	}
	count = 1;
	while (ft_fnl(str) && (count != 0))
	{
		count = read(fd, buffer, BUFFER_SIZE);
		buffer[count] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	result = till_next_line(str);
	str = after_next_line(str);
	return result;
}

#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd = open("ft_txt", O_RDONLY);
	char	*str;
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
}