/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:15:09 by avaganay          #+#    #+#             */
/*   Updated: 2023/02/05 12:33:49 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close( t_data *img)
{
	ft_allfree(img);
	exit(0);
}

int	ft_key(int keycode, t_data *img)
{
	if (keycode == ESC_KEY || img->win)
	{
		ft_allfree(img);
		exit(0);
	}
	if (keycode == W_KEY)
		ft_mouv(img, W_KEY);
	else if (keycode == S_KEY)
		ft_mouv(img, S_KEY);
	else if (keycode == A_KEY)
		ft_mouv(img, A_KEY);
	else if (keycode == D_KEY)
		ft_mouv(img, D_KEY);
	else if (keycode == SPACE_KEY)
		ft_kame(img);
	return (0);
}

int	ft_doublefreetab(char **tabmap, char **tabmapclone)
{
	ft_freetab(tabmapclone, 0);
	ft_freetab(tabmap, 1);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	img;
	t_map	map;
	char	**tabmap;
	char	**tabmapclone;
	int		fd;

	if (ft_checkarg(argc, argv))
		exit(ft_printf("%s", "Error\nBad argument\n"));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || fd > 1023)
		exit(ft_printf("%s", "Error\nFile descriptor\n"));
	tabmap = ft_parsing(argv[1]);
	tabmapclone = ft_parsing(argv[1]);
	if (!tabmap || ft_checkmap(tabmap, tabmapclone))
		exit(ft_doublefreetab(tabmap, tabmapclone));
	ft_freetab(tabmapclone, 0);
	if (ft_init_struct(tabmap, &map, &img) || ft_init_images(&map, &img))
		exit(ft_printf("%s", "Error\nBad init\n"));
	img.map = map;
	mlx_hook(img.win_ptr, 2, (1L << 0), ft_key, &img);
	mlx_hook(img.win_ptr, 17, (1L << 17), ft_close, &img);
	mlx_loop_hook(img.mlx_ptr, ft_anime, &img);
	mlx_loop(img.mlx_ptr);
	return (0);
}
