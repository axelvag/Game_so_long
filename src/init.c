/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:10:07 by avaganay          #+#    #+#             */
/*   Updated: 2023/02/05 12:32:44 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_init_struct(char **tabmap, t_map *map, t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (tabmap[i])
	{
		j = 0;
		while (tabmap[i][j])
			j++;
		i++;
	}
	img->win = 0;
	img->mouv = 0;
	img->mlx_ptr = mlx_init();
	if (!img->mlx_ptr)
		return (1);
	img->win_ptr = mlx_new_window(img->mlx_ptr, j * 100,
			i * 100, "DRAGON BALL DEVOLUTION");
	img->img = mlx_new_image(img->mlx_ptr, 1920, 1080);
	if (!img->win_ptr || !img->img)
		return (1);
	map->map = tabmap;
	img->nb_item = ft_count_item(tabmap);
	return (0);
}

void	ft_init_images2(t_map *map, t_data *img)
{
	map->player_up = mlx_xpm_file_to_image(img->mlx_ptr, \
			"./assets/xpm/playeur_up.xpm", &(img->pix_hei), &(img->pix_hei));
	map->player_left = mlx_xpm_file_to_image(img->mlx_ptr, \
			"./assets/xpm/playeur_left.xpm", &(img->pix_hei), &(img->pix_hei));
	map->player_right = mlx_xpm_file_to_image(img->mlx_ptr, \
			"./assets/xpm/playeur_right.xpm", &(img->pix_hei), &(img->pix_hei));
	map->player_down = mlx_xpm_file_to_image(img->mlx_ptr, \
			"./assets/xpm/playeur_down.xpm", &(img->pix_hei), &(img->pix_hei));
	map->ennemi_up = mlx_xpm_file_to_image(img->mlx_ptr, \
			"./assets/xpm/ennemi_up.xpm", &(img->pix_hei), &(img->pix_hei));
	map->ennemi_down = mlx_xpm_file_to_image(img->mlx_ptr, \
			"./assets/xpm/ennemi_down.xpm", &(img->pix_hei), &(img->pix_hei));
	map->kame = mlx_xpm_file_to_image(img->mlx_ptr, \
			"./assets/xpm/kame.xpm", &(img->pix_hei), &(img->pix_hei));
}

int	ft_init_images(t_map *map, t_data *img)
{
	img->pix_hei = 100;
	map->floor = mlx_xpm_file_to_image(img->mlx_ptr, \
			"./assets/xpm/floor.xpm", &(img->pix_hei), &(img->pix_hei));
	map->wall = mlx_xpm_file_to_image(img->mlx_ptr, \
			"./assets/xpm/wall.xpm", &(img->pix_hei), &(img->pix_hei));
	map->exit = mlx_xpm_file_to_image(img->mlx_ptr, \
			"./assets/xpm/exit.xpm", &(img->pix_hei), &(img->pix_hei));
	map->item = mlx_xpm_file_to_image(img->mlx_ptr, \
			"./assets/xpm/item.xpm", &(img->pix_hei), &(img->pix_hei));
	ft_init_images2(map, img);
	if (map->floor == NULL || map->wall == NULL || map->exit == NULL
		|| map->item == NULL || map->player_up == NULL
		|| map->player_left == NULL
		|| map->player_right == NULL || map->player_down == NULL
		|| map->ennemi_up == NULL
		|| map->ennemi_down == NULL || map->kame == NULL)
		return (1);
	return (0);
}

void	ft_draw_map2(t_map map, t_data img, int i, int j)
{
	if (map.map[i][j] == 'U')
		mlx_put_image_to_window(img.mlx_ptr, img.win_ptr,
			map.player_up, j * 100, i * 100);
	if (map.map[i][j] == 'R')
		mlx_put_image_to_window(img.mlx_ptr, img.win_ptr,
			map.player_right, j * 100, i * 100);
	if (map.map[i][j] == 'L')
		mlx_put_image_to_window(img.mlx_ptr, img.win_ptr,
			map.player_left, j * 100, i * 100);
	if (map.map[i][j] == 'E')
		mlx_put_image_to_window(img.mlx_ptr, img.win_ptr,
			map.exit, j * 100, i * 100);
	if (map.map[i][j] == 'C')
		mlx_put_image_to_window(img.mlx_ptr, img.win_ptr,
			map.item, j * 100, i * 100);
}

void	ft_draw_map(t_map map, t_data img)
{
	int		i;
	int		j;
	char	*count;

	i = 0;
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j])
		{
			if (map.map[i][j] == '0')
				mlx_put_image_to_window(img.mlx_ptr, img.win_ptr,
					map.floor, j * 100, i * 100);
			if (map.map[i][j] == '1')
				mlx_put_image_to_window(img.mlx_ptr, img.win_ptr,
					map.wall, j * 100, i * 100);
			ft_draw_map2(map, img, i, j);
			ft_draw_map3(map, img, i, j);
			j++;
		}
		i++;
	}
	count = ft_itoa(img.mouv);
	mlx_string_put(img.mlx_ptr, img.win_ptr, 40, 40, 0x00FF0000, count);
	free(count);
}
