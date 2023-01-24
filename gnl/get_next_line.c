/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsoymaz <fsoymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:40:29 by fatihsoymaz       #+#    #+#             */
/*   Updated: 2023/01/24 17:16:36 by fsoymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_read(int fd, char *str)
{
	int			count;
	char		*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	count = 1;
	while (ft_fnl(str) && (count != 0))
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count < 0)
		{
			free(buffer);
			free(str);
			return (0);
		}
		buffer[count] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(str);
		return (NULL);
	}
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	result = read_line(str);
	str = next_line(str);
	return (str);
}

int	a(char	*str)
{
	int i = 0;
	while(str[i])
	{
		i++;
	}
	return (i);
}
#include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd = open("ft_txt", O_RDONLY);
	int	i;
	i = ft_strlen(get_next_line(fd));
	printf("%d", i);
	int a = 0;
	char *str;
	while (i  >= a)
	{
		str = get_next_line(fd);
		printf("%s", str);
		a++;
	}
	free(str);

}
