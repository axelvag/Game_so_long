/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:18:12 by avaganay          #+#    #+#             */
/*   Updated: 2023/01/29 13:24:41 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_map3(t_map map, t_data img, int i, int j)
{
	if (map.map[i][j] == 'V')
		mlx_put_image_to_window(img.mlx_ptr, img.win_ptr,
			map.ennemi_up, j * 100, i * 100);
	if (map.map[i][j] == 'W')
		mlx_put_image_to_window(img.mlx_ptr, img.win_ptr,
			map.ennemi_down, j * 100, i * 100);
	if (map.map[i][j] == 'K')
		mlx_put_image_to_window(img.mlx_ptr, img.win_ptr,
			map.kame, j * 100, i * 100);
	if (map.map[i][j] == 'P')
		mlx_put_image_to_window(img.mlx_ptr, img.win_ptr,
			map.player_down, j * 100, i * 100);
}
