/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:54:32 by gade-oli          #+#    #+#             */
/*   Updated: 2023/01/27 17:12:04 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*res;

	res = malloc(BUFFER_SIZE);
	if (res == NULL)
		return (NULL);
	read(fd, res, BUFFER_SIZE);
	return (res);
}
