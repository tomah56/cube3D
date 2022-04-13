/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_mykey_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokesi <ttokesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:50:50 by ttokesi           #+#    #+#             */
/*   Updated: 2022/04/13 00:02:13 by ttokesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#define steppp 8 

static int	st_p(t_vars *g, int x, int y)
{
	if ((g->map)[y / g->sizer][x / g->sizer] == 'C')
	{
		(g->collect)--;
		(g->map)[y / g->sizer][x / g->sizer] = '0';
	}
	if (g->collect == 0 && (g->map)[y / g->sizer][x / g->sizer] == 'E' && g->enemy > -1)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->im[WIN].l,
			(g->wi_x - 4) * 32 + 1, (g->he_y - 4) * 32 + 1);
		g->collect = -1;
	}
	if ((g->map)[y / g->sizer][x / g->sizer] == '1' || (g->map)[y / g->sizer][x / g->sizer] == 'E')
		return (0);
	return (1);
}

static int	move_up_down(t_vars *g, int key, int r)
{

	if (key == 13)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->im[FLOOR].l, g->fi_x, g->fi_y);
		if (g->fi_y > g->sizer && st_p(g, g->fi_x, g->fi_y - steppp))
			g->fi_y -= steppp;
		mlx_put_image_to_window(g->mlx, g->win, g->im[r].l, g->fi_x, g->fi_y);
	}
	if (key == 1)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->im[FLOOR].l, g->fi_x, g->fi_y);
		if (g->fi_y < (g->he_y * g->sizer) - 12 && st_p(g, g->fi_x, g->fi_y + steppp))
			g->fi_y += steppp;
		mlx_put_image_to_window(g->mlx, g->win, g->im[FIG1].l, g->fi_x, g->fi_y);
	}
	return (0);
}
// left 123 right 124
static int	move_right_left(t_vars *g, int key, int r)
{
	if (key == 2)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->im[4].l, g->fi_x, g->fi_y);
		if (g->fi_x < (g->wi_x * g->sizer ) - 12 && st_p(g, g->fi_x + steppp, g->fi_y))
			g->fi_x += steppp;
		mlx_put_image_to_window(g->mlx, g->win, g->im[r].l, g->fi_x, g->fi_y);
	}
	if (key == 0)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->im[4].l, g->fi_x, g->fi_y);
		if (g->fi_x > g->sizer && st_p(g, g->fi_x - steppp, g->fi_y))
			g->fi_x -= steppp;
		mlx_put_image_to_window(g->mlx, g->win, g->im[r].l, g->fi_x, g->fi_y);
	}
	return (0);
}

int	key_hook(int keycode, t_vars *g)
{
	int	fignum;

	fignum = 0;
	if (g->collect > -1)
	{
		// if (keycode == 12g->sizer || keycode == 125 || keycode == 124
		// 	|| keycode == 123)
		// 	(g->count)++;
		// if (keycode == 13 || keycode == 1 || keycode == 2 || keycode == 0)
		// 	(g->count)++;
		// put_num_screen(g);
		if (keycode == 123 || keycode == 124)
			look_around(keycode, g);
		if (keycode == 13)
			move_up_down(g, keycode, fignum);
		if (keycode == 1)
			move_up_down(g, keycode, fignum);
		if (keycode == 2)
			move_right_left(g, keycode, fignum);
		if (keycode == 0)
			move_right_left(g, keycode, fignum);
	}
	render_smallmap(g);
	return (0);
}
