/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:33:32 by avaganay          #+#    #+#             */
/*   Updated: 2023/01/18 13:39:49 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlengnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlengnl(src);
	i = 0;
	if (size == 0)
		return (src_len);
	while (size > 1 && src[i])
	{
		dest[i] = src[i];
		i++;
		size--;
	}
	dest[i] = '\0';
	return (src_len);
}

size_t	ft_found_newline(char *surplus)
{
	size_t	i;

	i = 0;
	if (surplus == NULL)
		return (0);
	while (surplus[i])
	{
		if (surplus[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	i;
	size_t	k;

	k = 0;
	i = 0;
	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (join == NULL)
		return (NULL);
	while (s1[i])
		join[i++] = s1[k++];
	free (s1);
	k = 0;
	while (s2[k])
		join[i++] = s2[k++];
	join[i] = '\0';
	return (join);
}
