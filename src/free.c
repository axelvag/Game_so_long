/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:22:50 by axel              #+#    #+#             */
/*   Updated: 2023/02/05 12:28:00 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_freeparsingerror(char **map, char *mapjoin)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	free(mapjoin);
	return (1);
}

void	ft_freeimage(t_data *img)
{
	mlx_destroy_image(img->mlx_ptr, img->map.floor);
	mlx_destroy_image(img->mlx_ptr, img->map.wall);
	mlx_destroy_image(img->mlx_ptr, img->map.exit);
	mlx_destroy_image(img->mlx_ptr, img->map.item);
	mlx_destroy_image(img->mlx_ptr, img->map.player_up);
	mlx_destroy_image(img->mlx_ptr, img->map.player_left);
	mlx_destroy_image(img->mlx_ptr, img->map.player_right);
	mlx_destroy_image(img->mlx_ptr, img->map.player_down);
	mlx_destroy_image(img->mlx_ptr, img->map.ennemi_up);
	mlx_destroy_image(img->mlx_ptr, img->map.ennemi_down);
	mlx_destroy_image(img->mlx_ptr, img->map.kame);
	mlx_destroy_image(img->mlx_ptr, img->img);
	mlx_clear_window(img->mlx_ptr, img->win_ptr);
	mlx_destroy_window(img->mlx_ptr, img->win_ptr);
	mlx_destroy_display(img->mlx_ptr);
	free(img->mlx_ptr);
}

int	ft_allfree(t_data *img)
{
	int	i;

	i = 0;
	while (img->map.map[i])
	{
		free(img->map.map[i]);
		i++;
	}
	free(img->map.map);
	ft_freeimage(img);
	return (0);
}

int	ft_allfreeerror(t_data *img)
{
	int	i;

	i = 0;
	while (img->map.map[i])
	{
		free(img->map.map[i]);
		i++;
	}
	free(img->map.map);
	ft_freeimage(img);
	ft_printf("%s", "Error");
	return (1);
}

int	ft_freetab(char **tab, int e)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	if (e == 1)
		ft_printf("%s", "Error\nBad map argument\n");
	else if (e == 2)
		ft_printf("%s", "Error\nBad map argument\n");
	return (1);
}
