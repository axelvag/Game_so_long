/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:28:29 by avaganay          #+#    #+#             */
/*   Updated: 2023/02/03 15:17:51 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoinsolong(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	ptr = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}

void	ft_init0parsing(char	**mapjoin, char	***map)
{
	*mapjoin = NULL;
	*map = NULL;
}

void	ft_checknparsing(char	**map, char	*mapjoin)
{
	if (ft_checkn(map, mapjoin))
		exit(ft_printf("%s", "Error\nmap not rectangular\n"));
}

char	**ft_parsing(char *filename)
{
	char	*mapjoin;
	char	**map;
	int		fd;
	char	*line;
	char	*temp;

	ft_init0parsing(&mapjoin, &map);
	fd = open(filename, O_RDONLY);
	mapjoin = get_next_line(fd);
	if (!mapjoin)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		temp = mapjoin;
		mapjoin = ft_strjoinsolong(temp, line);
		free(line);
		free(temp);
		line = get_next_line(fd);
	}
	close(fd);
	map = ft_split(mapjoin, '\n');
	ft_checknparsing(map, mapjoin);
	free(mapjoin);
	return (map);
}
