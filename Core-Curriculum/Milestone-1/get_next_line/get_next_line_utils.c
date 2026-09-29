/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekypraio <ekypraio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 17:38:09 by ekypraio          #+#    #+#             */
/*   Updated: 2026/09/03 13:33:15 by ekypraio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

static char	*grow_storage(char *s1, size_t length, size_t *capacity)
{
	char	*res;
	size_t	i;

	while (*capacity < length)
		*capacity *= 2;
	res = malloc(*capacity);
	if (!res)
		return (free(s1), NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	free(s1);
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	static size_t	capacity;
	size_t			length;
	size_t			i;

	if (!s1)
	{
		capacity = 1;
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (length > capacity)
		s1 = grow_storage(s1, length, &capacity);
	if (!s1)
		return (NULL);
	i = ft_strlen(s1);
	while (*s2)
		s1[i++] = *s2++;
	s1[i] = '\0';
	return (s1);
}

char	*update_storage(char *storage)
{
	int		i;
	char	*new_storage;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	i++;
	new_storage = ft_strjoin(NULL, storage + i);
	if (!new_storage)
		return (free(storage), NULL);
	free(storage);
	return (new_storage);
}
