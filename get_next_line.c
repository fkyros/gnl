/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:54:32 by gade-oli          #+#    #+#             */
/*   Updated: 2023/02/23 19:43:36 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*given a buffer, returns the first line encountered*/
char	*gen_line(char *read)
{
	char	*line;
	int		i;
	int		j;

	if (!read || !*read)
		return (NULL);
	i = 0;
	while (read[i] != '\0' && read[i] != '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = read[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*rm_line(char *line)
{
	char	*res;
	int		i;
	int		j;
	int		tam;

	i = 0;
	if (!line || !*line)
		return (NULL);
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	tam = ft_strlen(line) - i;
	res = malloc(tam);
	j = 0;
	i++;
	while (j < tam)
	{
		res[j] = line[i + j];
		j++;
	}
	res[j] = '\0';
	free(line);
	return (res);
}

char	*get_next_line(int fd)
{
	static char		*reading = NULL;
	char			tmp[BUFFER_SIZE + 1];
	ssize_t			bytesread;
	char			*line;

	if (!reading)
	{
		reading = malloc(sizeof(char) * 1000);
		reading[0] = '\0';
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytesread = 1;
	while (bytesread > 0 && ft_strchr(reading, '\n') == NULL)
	{
		bytesread = read(fd, tmp, BUFFER_SIZE);
		if (bytesread < 0)
		{
			free(reading);
			return (NULL);
		}
		tmp[bytesread] = '\0';
		reading = ft_strjoin(reading, tmp);
	}
	line = gen_line(reading);
	reading = rm_line(reading);
	return (line);
}
