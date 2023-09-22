/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:03:44 by avaganay          #+#    #+#             */
/*   Updated: 2023/01/29 16:22:32 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_findplayeur(char **map, t_vec *vec)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				vec->x = j;
				vec->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_countitempath(char **map, t_vec *vec)
{
	int	i;
	int	j;

	vec->item = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				vec->item = vec->item + 1;
			}
			if (map[i][j] == 'E')
			{
				vec->exit = 1;
			}
			j++;
		}
		i++;
	}
}

int	ft_recursion(char **map, int x, int y, t_vec *vec)
{
	if (map[y][x] == 'C')
		vec->item--;
	if (map[y + 1][x] == 'E' || map[y - 1][x] == 'E' ||
		map[y][x + 1] == 'E' || map[y][x - 1] == 'E')
		vec->exit--;
	map[y][x] = '1';
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'V' ||
		map[y + 1][x] == 'W' || map[y + 1][x] == 'C')
		ft_recursion(map, x, y + 1, vec);
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'V' ||
		map[y - 1][x] == 'W' || map[y - 1][x] == 'C')
		ft_recursion(map, x, y - 1, vec);
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'V' ||
		map[y][x + 1] == 'W' || map[y][x + 1] == 'C')
		ft_recursion(map, x + 1, y, vec);
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'V' ||
		map[y][x - 1] == 'W' || map[y][x - 1] == 'C')
		ft_recursion(map, x - 1, y, vec);
	return (1);
}

int	ft_pathfinding(char **map)
{
	t_vec	vec;

	ft_countitempath(map, &vec);
	ft_findplayeur(map, &vec);
	ft_recursion(map, vec.x, vec.y, &vec);
	if (vec.item == 0 && vec.exit <= 0)
		return (0);
	return (1);
}
