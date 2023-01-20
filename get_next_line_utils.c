/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatihsoymaz <fatihsoymaz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:51:55 by fatihsoymaz       #+#    #+#             */
/*   Updated: 2023/01/20 14:42:54 by fatihsoymaz      ###   ########.fr       */
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

int	ft_fnl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strjoin(char *str, char	*buffer)
{
	size_t		i;
	size_t		j;
	char		*result;

	i = -1;
	j = 0;
	if (!str)
	{
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
	}
	result = malloc(sizeof(char) * ft_strlen(str) + ft_strlen(buffer) + 1);
	if (!result)
		return (NULL);
	while (str[++i])
		result[i] = str[i];
	while (buffer[j])
		result[i++] = buffer[j++];
	free(str);
	result[i] = '\0';
	return (result);
}

char	*till_next_line(char	*holder)
{
	size_t	i;
	char	*result;

	if (*holder == 0)
		return (NULL);
	i = 0;
	while (holder[i] && holder[i] != '\n')
		i++;
	result = malloc(sizeof(char) * i + 2);
	if (!result)
		return (NULL);
	i = 0;
	while (holder[i] && holder[i] != '\n')
	{
		result[i] = holder[i];
		i++;
	}
	if (holder[i] == '\n')
		result[i++] = '\n';
	result[i] = '\0';
	return (result);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	if (!s)
		return (0);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = 0;
	return (result);
}

char	*after_next_line(char *holder)
{
    int		i;
    char	*result;

	i = 0;
	while (holder[i] != '\n' && holder[i] != '\0')
		i++;
	if (holder[i] == '\n')
		i++;
	result = ft_substr(holder, i, ft_strlen(holder) - i);
	free(holder);
	return (result);
}
