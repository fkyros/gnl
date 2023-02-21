/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:54:32 by gade-oli          #+#    #+#             */
/*   Updated: 2023/02/20 21:27:36 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*reading;
	char	*line;
	char	tmp[BUFFER_SIZE + 1];
	ssize_t	bytesread;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytesread = 1;
	while (ft_strchr(reading, '\n') && bytesread > 0)
	{
		bytesread = read(fd, tmp, BUFFER_SIZE);
		if (bytesread < 0)
		{
			//free(reading); //???????????????
			return (NULL);
		}
		tmp[bytesread] = '\0';

	}
	return (line);
}
