/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:45:23 by avaganay          #+#    #+#             */
/*   Updated: 2023/02/05 12:33:01 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line_bonus.h"
# include "../Libft/libft.h"
# include "../ft_printf/ft_printf.h"

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define ESC_KEY 65307
# define SPACE_KEY 32

typedef struct s_vec
{
	int	x;
	int	y;
	int	item;
	int	exit;
}				t_vec;

typedef struct s_map
{
	char	**map;
	void	*floor;
	void	*wall;
	void	*exit;
	void	*item;
	void	*player_up;
	void	*player_left;
	void	*player_right;
	void	*player_down;
	void	*ennemi_up;
	void	*ennemi_down;
	void	*kame;
}				t_map;

typedef struct s_data {
	void	*img;
	int		pix_hei;
	void	*mlx_ptr;
	void	*win_ptr;
	int		nb_item;
	int		win;
	int		mouv;
	t_map	map;
}				t_data;

char	**ft_parsing(char *filename);
int		ft_checkarg(int argc, char **argv);
int		ft_checkmap(char **map, char **mapclone);
int		ft_checknumber(char **map);
int		ft_checkn(char **map, char *mapjoin);
int		ft_init_struct(char **tabmap, t_map *map, t_data *img);
int		ft_init_images(t_map *map, t_data *img);
void	ft_draw_map(t_map map, t_data img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_mouv(t_data *img, int keycode);
int		ft_count_item(char **map);
int		ft_win(t_data *img);
int		ft_allfree(t_data *img);
int		ft_allfreeerror(t_data *img);
int		ft_freeparsingerror(char **map, char *mapjoin);
int		ft_freetab(char **tab, int e);
int		ft_anime(t_data *img);
void	ft_kame(t_data *img);
int		ft_pathfinding(char **map);
void	ft_draw_map3(t_map map, t_data img, int i, int j);
void	ft_mouv2(t_data *img, int keycode, int i, int j);
void	ft_mouv_w(t_data *img, int i, int j);
void	ft_mouv_s(t_data *img, int i, int j);
void	ft_mouv_a(t_data *img, int i, int j);
void	ft_mouv_d(t_data *img, int i, int j);

#endif