/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checknumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:40:36 by avaganay          #+#    #+#             */
/*   Updated: 2023/01/29 15:55:54 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkn(char **map, char *mapjoin)
{
	size_t	i;
	size_t	nbmapjoin;

	i = 0;
	nbmapjoin = 0;
	while (i <= ft_strlen(mapjoin))
	{
		if (mapjoin[i] == '\n')
			nbmapjoin++;
		i++;
	}
	i = 0;
	nbmapjoin++;
	while (map[i])
	{
		i++;
	}
	if (i != nbmapjoin)
	{
		ft_freetab(map, 0);
		free(mapjoin);
		exit(ft_printf("%s", "Error\nmap not rectangular\n"));
	}
	return (0);
}

void	ft_init0checknumber(int *item, size_t *j, int *exit, int *start)
{
	*item = 0;
	*j = 0;
	*exit = 0;
	*start = 0;
}

int	ft_checknumber(char **map)
{
	size_t	i;
	size_t	j;
	int		exit;
	int		start;
	int		item;

	i = 0;
	ft_init0checknumber(&item, &j, &exit, &start);
	while (map[i])
	{
		j = -1;
		while (++j <= ft_strlen(map[i]))
		{
			if (map[i][j] == 'E')
				exit = exit + 1;
			else if (map[i][j] == 'P')
				start = start + 1;
			else if (map[i][j] == 'C')
				item = 1;
		}
		i++;
	}
	if (exit != 1 || start != 1 || item == 0)
		return (1);
	return (0);
}
