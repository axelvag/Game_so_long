/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:58:20 by avaganay          #+#    #+#             */
/*   Updated: 2023/01/29 13:30:02 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mouv_w(t_data *img, int i, int j)
{
	if (img->map.map[i - 1][j] == 'V' || img->map.map[i - 1][j] == 'W')
	{
		img->win = 1;
		return ;
	}
	if (img->map.map[i - 1][j] == 'E')
	{
		if (ft_win(img))
			img->win = 1;
		return ;
	}
	if (img->map.map[i - 1][j] == 'C')
		img->nb_item = img->nb_item - 1;
	if (img->map.map[i - 1][j] != '1')
	{
		img->mouv = img->mouv + 1;
		img->map.map[i - 1][j] = 'U';
		img->map.map[i][j] = '0';
		ft_draw_map(img->map, *img);
	}
}

void	ft_mouv_s(t_data *img, int i, int j)
{
	if (img->map.map[i + 1][j] == 'V' || img->map.map[i - 1][j] == 'W')
	{
		img->win = 1;
		return ;
	}
	if (img->map.map[i + 1][j] == 'E')
	{
		if (ft_win(img))
			img->win = 1;
		return ;
	}
	if (img->map.map[i + 1][j] == 'C')
		img->nb_item = img->nb_item - 1;
	if (img->map.map[i + 1][j] != '1')
	{
		img->mouv = img->mouv + 1;
		img->map.map[i + 1][j] = 'P';
		img->map.map[i][j] = '0';
		ft_draw_map(img->map, *img);
	}
}

void	ft_mouv_a(t_data *img, int i, int j)
{
	if (img->map.map[i][j - 1] == 'V' || img->map.map[i][j - 1] == 'W')
	{
		img->win = 1;
		return ;
	}
	if (img->map.map[i][j - 1] == 'E')
	{
		if (ft_win(img))
			img->win = 1;
		return ;
	}
	if (img->map.map[i][j - 1] == 'C')
		img->nb_item = img->nb_item - 1;
	if (img->map.map[i][j - 1] != '1')
	{
		img->mouv = img->mouv + 1;
		img->map.map[i][j - 1] = 'L';
		img->map.map[i][j] = '0';
		ft_draw_map(img->map, *img);
	}
}

void	ft_mouv_d(t_data *img, int i, int j)
{
	if (img->map.map[i][j + 1] == 'V' || img->map.map[i][j + 1] == 'W')
	{
		img->win = 1;
		return ;
	}
	if (img->map.map[i][j + 1] == 'E')
	{
		if (ft_win(img))
			img->win = 1;
		return ;
	}
	if (img->map.map[i][j + 1] == 'C')
		img->nb_item = img->nb_item - 1;
	if (img->map.map[i][j + 1] != '1')
	{
		img->mouv = img->mouv + 1;
		img->map.map[i][j + 1] = 'R';
		img->map.map[i][j] = '0';
		ft_draw_map(img->map, *img);
	}
}

void	ft_mouv(t_data *img, int keycode)
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
				ft_mouv2(img, keycode, i, j);
			}
			j++;
		}
		i++;
	}
}
