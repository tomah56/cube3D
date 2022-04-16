/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokesi <ttokesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:39:00 by oipadeol          #+#    #+#             */
/*   Updated: 2022/04/13 15:28:55 by ttokesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_v(int *dxy, int *xyi, int *count)
{
	*count = 0;
	if (*dxy < 0)
	{	
		*xyi = -1;
		*dxy = -1 * (*dxy);
	}
}

static void	plotlinelow(int x0_y0[2], int x1_y1[2], t_vars *vars, int color)
{
	int	dx;
	int	dy;
	int	yi;
	int	diff;
	int	count;

	dx = x1_y1[0] - x0_y0[0];
	dy = x1_y1[1] - x0_y0[1];
	yi = 1;
	diff = (2 * dy) - dx;
	init_v(&dy, &yi, &count);
	while (x0_y0[0] <= x1_y1[0])
	{
		my_mlx_pixel_put(vars, x0_y0[0], x0_y0[1], color);
		if (diff > 0)
		{
			x0_y0[1] = x0_y0[1] + yi;
			diff = diff + (2 * (dy - dx));
		}
		else
			diff = diff + (2 * dy);
		(x0_y0[0])++;
	}
}

static void	plotlinehigh(int x0_y0[2], int x1_y1[2], t_vars *vars, int color)
{
	int	dx;
	int	dy;
	int	xi;
	int	diff;
	int	count;

	dx = x1_y1[0] - x0_y0[0];
	dy = x1_y1[1] - x0_y0[1];
	xi = 1;
	diff = (2 * dx) - dy;
	init_v(&dx, &xi, &count);
	while (x0_y0[1] <= x1_y1[1])
	{
		my_mlx_pixel_put(vars, x0_y0[0], x0_y0[1], color);
		if (diff > 0)
		{
			x0_y0[0] = x0_y0[0] + xi;
			diff = diff + (2 * (dx - dy));
		}
		else
			diff = diff + (2 * dx);
		(x0_y0[1])++;
	}
}

void	plotline_color(int x0, int y0, int x1, int y1, t_vars *vars, int color)
{
	int	x0_y0[2];
	int	x1_y1[2];

	x0_y0[0] = x0;
	x0_y0[1] = y0;
	x1_y1[0] = x1;
	x1_y1[1] = y1;
	if (ft_absolute(x1_y1[1] - x0_y0[1]) < ft_absolute(x1_y1[0] - x0_y0[0]))
	{
		if (x0_y0[0] > x1_y1[0])
			plotlinelow(x1_y1, x0_y0, vars, color);
		else
			plotlinelow(x0_y0, x1_y1, vars, color);
		return ;
	}
	else if (x0_y0[1] > x1_y1[1])
		plotlinehigh(x1_y1, x0_y0, vars, color);
	else
		plotlinehigh(x0_y0, x1_y1, vars, color);
}
