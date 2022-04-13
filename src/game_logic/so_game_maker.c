/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_game_maker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokesi <ttokesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:54:13 by ttokesi           #+#    #+#             */
/*   Updated: 2022/04/12 22:48:01 by ttokesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	close1(int keycode, t_vars *game)
{
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

static int	close12(t_vars *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
	return (0);
}

static void	set_startvalues(t_vars *game)
{
	game->enemy = 0;
	game->count = 0;
	game->sizer = 8; // size of small map
	game->fi_x = 8;
	game->fi_y = 8;
	game->collect = 0;
	game->check = 0;
	game->bh_x = -1;
	game->bh_y = -1;
	game->b2_x = -1;
	game->b2_y = -1;
	game->pa = 0.0;
	game->pdx = 0.0;
	game->pdy = 0.0;
}

void	game_starter(t_vars *game)
{

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 1280, 960,
			"42 cube3D");

// pixel part
 	game->img = mlx_new_image(game->mlx, 1280, 960);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_length, &game->endian);
	my_mlx_pixel_put(game, game->fi_x + 500, game->fi_y + 500, 0x00CCFF66);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 000, 000);


	mlx_hook(game->win, 2, 1L << 2, close1, game);
	mlx_hook(game->win, 17, 1L << 17, close12, game);
	img_handler(game);
	set_startvalues(game);
	mlx_key_hook(game->win, key_hook, game);
	load_fields(game);
	// game_screen_maker(game);
	mlx_loop_hook(game->mlx, my_timer, game);
	mlx_loop(game->mlx);
}
