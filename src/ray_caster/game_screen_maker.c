/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_screen_maker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokesi <ttokesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:36:32 by ttokesi           #+#    #+#             */
/*   Updated: 2022/04/12 23:04:19 by ttokesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cub3d.h"

int	create_rgb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

void game_screen_maker(t_vars *game)
{
	int i;
	int j;
	int color;

	i = 0;
	j = 0;
	color = create_rgb(111, 95, 118);
	while (j < 480)
	{
		i = 0;
		while (i < 1280)
		{
			my_mlx_pixel_put(game, i, j, color);
			i++;
		}
		j++;
	}
	// color = 0x00CCFF66;
	color = create_rgb(1, 215, 88);
	while (j < 960)
	{
		i = 0;
		while (i < 1280)
		{
			my_mlx_pixel_put(game, i, j, color);
			i++;
		}
		j++;
	}
}