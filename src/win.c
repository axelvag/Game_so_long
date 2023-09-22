/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:22:17 by avaganay          #+#    #+#             */
/*   Updated: 2023/02/03 15:38:31 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_kill(t_data *img, int i, int j)
{
	if (img->map.map[i + 1][j] == 'V' || img->map.map[i + 1][j] == 'W')
		img->map.map[i + 1][j] = '0';
	if (img->map.map[i - 1][j] == 'V' || img->map.map[i - 1][j] == 'W')
		img->map.map[i - 1][j] = '0';
	if (img->map.map[i][j + 1] == 'V' || img->map.map[i][j + 1] == 'W')
		img->map.map[i][j + 1] = '0';
	if (img->map.map[i][j - 1] == 'V' || img->map.map[i][j - 1] == 'W')
		img->map.map[i][j - 1] = '0';
}

void	ft_kame(t_data *img)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (img->map.map[i] && k == 0)
	{
		j = 0;
		while (img->map.map[i][j] && k == 0)
		{
			if (img->map.map[i][j] == 'P' || img->map.map[i][j] == 'U' ||
				img->map.map[i][j] == 'R' || img->map.map[i][j] == 'L')
			{
				k = 1;
				img->map.map[i][j] = 'K';
				ft_draw_map(img->map, *img);
				ft_kill(img, i, j);
				img->map.map[i][j] = 'P';
			}
			j++;
		}
		i++;
	}
}

int	ft_anime(t_data *img)
{
	static int	anime = 0;
	int			i;
	int			j;

	i = 0;
	anime++;
	if (anime >= 500)
	{
		anime = 0;
		while (img->map.map[i])
		{
			j = 0;
			while (img->map.map[i][j])
			{
				if (img->map.map[i][j] == 'V')
					img->map.map[i][j] = 'W';
				else if (img->map.map[i][j] == 'W')
					img->map.map[i][j] = 'V';
				j++;
			}
			i++;
		}
	}
	ft_draw_map(img->map, *img);
	return (0);
}

int	ft_count_item(char **map)
{
	int	item;
	int	i;
	int	j;

	i = 0;
	item = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				item++;
			j++;
		}
		i++;
	}
	return (item);
}

int	ft_win(t_data *img)
{
	if (img->nb_item == 0)
		return (1);
	return (0);
}
