/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:22:07 by gade-oli          #+#    #+#             */
/*   Updated: 2023/02/23 19:30:03 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	if (!s)
		return (NULL);
	while (found == 0 && s[i] != '\0')
	{
		if (s[i] == (char)c)
			found = 1;
		else
			i++;
	}
	if ((char)c == '\0' && s[i] == '\0')
		found = 1;
	if (found)
		return ((char *)(s + i));
	return (NULL);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	copy_string_from_index(const char *src, char *dst, int i)
{
	int	j;

	j = 0;
	while (src[j])
	{
		dst[i] = src[j];
		j++;
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		tam;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	tam = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *) malloc(tam);
	if (res == NULL)
		return (NULL);
	if (s1 != NULL)
		copy_string_from_index(s1, res, 0);
	if (s2 != NULL)
		copy_string_from_index(s2, res, ft_strlen(s1));
	res[tam - 1] = '\0';
	return (res);
}
