/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:45:17 by avaganay          #+#    #+#             */
/*   Updated: 2023/02/03 15:24:54 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkarg(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
		return (1);
	while (argv[1][i])
	{
		if (argv[1][i] == '.' && argv[1][i + 1] == 'b' &&
			argv[1][i + 2] == 'e' && argv[1][i + 3] == 'r')
			return (0);
		i++;
	}
	return (1);
}

int	ft_checksquare(char **map)
{
	int		i;
	size_t	size;

	i = 0;
	size = ft_strlen(map[i]);
	if (map[0][0] == '\n')
		return (1);
	while (map[i])
	{
		if (size != ft_strlen(map[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_checkitem(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (j <= ft_strlen(map[i]))
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C' &&
				map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'V' &&
				map[i][j] != 'W' && map[i][j] != '\n' && map[i][j] != '\0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_checkwall(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (map[0][i++])
		if ((map[0][i] != '1' && map[0][i] != '\0') || map[0][0] != '1')
			return (1);
	while (map[j + 1])
	{
		if (map[j][0] != '1' || map[j][ft_strlen(map[j]) - 1] != '1')
			return (1);
		j++;
	}
	i = 0;
	while (map[j][i])
	{
		if (map[j][i] != '1' && map[j][i] != '\0')
			return (1);
		i++;
	}
	return (0);
}

int	ft_checkmap(char **map, char **mapclone)
{
	if (ft_checksquare(map))
		return (1);
	else if (ft_checkitem(map))
		return (1);
	else if (ft_checknumber(map))
		return (1);
	else if (ft_checkwall(map))
		return (1);
	else if (ft_pathfinding(mapclone))
		return (1);
	return (0);
}
