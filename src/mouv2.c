/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:26:55 by avaganay          #+#    #+#             */
/*   Updated: 2023/01/29 13:31:56 by avaganay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mouv2(t_data *img, int keycode, int i, int j)
{
	if (keycode == W_KEY)
		ft_mouv_w(img, i, j);
	if (keycode == S_KEY)
		ft_mouv_s(img, i, j);
	if (keycode == A_KEY)
		ft_mouv_a(img, i, j);
	if (keycode == D_KEY)
		ft_mouv_d(img, i, j);
}
