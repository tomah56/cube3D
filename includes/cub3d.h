/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttokesi <ttokesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:02:23 by oipadeol          #+#    #+#             */
/*   Updated: 2023/07/22 20:45:54 by ttokesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "get_line.h"
# include "ray_cast.h"
# include <pthread.h>

# define STEP 17
# define TILE_SIZE 64
# define MINI_SIZE 8
# define SCALE_TO_MINI 8
# define TILE_BIT 6
# define KILL_SHOT 32
# define WIN_WIDTH 1280
# define WIN_HEIGHT 920
# define POSITION_PUTIN_Y 430
# define RELATIVE_SIZE_PUTIN 1
# define SENSIBILITY 16
# define MINI_MAP_RAY_LEN 20

enum	e_keys
{
	A_KEY = 0,
	S_KEY = 1,
	D_KEY = 2,
	W_KEY = 13,
	SPACE_KEY = 49,
	LEFT_KEY = 123,
	RIGHT_KEY = 124,
	DOWN_KEY = 125,
	UP_KEY = 126
};

typedef struct s_vars
{
	t_img	image[IMAGE_COUNT];
	void	*mlx;
	void	*win;
	int		count;
	char	**map;
	void	*img;
	char	start_orientation;
	double	orient;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		player[2];
	int		putin[2];
	float	player_f[2];
	float	player_d[2];
	int		origin[2];
	int		floor_color;
	int		ceiling_color;
	char	**input;
	int		map_width;
	int		map_height;
	int		simul_loop;
	int		shoot;
	int		open_door;
	int		last_door[2];
	int		colore_shift;
	int		mouse;
	t_putin	par;
}				t_vars;

void	img_handler(t_vars *vars);

// ------- mlx  ----------
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
int		key_hook(int keycode, t_vars *vars);
int		mouse_hook(int x, int y, t_vars *vars);
int		clean_destroy(t_vars *vars);

// ------- input ---------
void	input_rows_init_player(int argc, char **argv, t_vars *vars);
int		check_valid(char **input, t_vars *vars);
void	standardize_input(char **str_ptr, int *max_len);
void	ft_error(char *str);

// ------ ray --------

void	plotline(int x0_y0[2], int x1_y1[2], t_vars *vars, int color);
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
void	draw_mini_map(t_vars *vars);
void	scale_image(t_vars *vars, t_img *image, double scale);
void	cast_rays(t_vars *vars);
void	init_look_up_down(t_vars *vars, t_ray *ray, float theta);
void	init_look_left_right(t_vars *vars, t_ray *ray, float theta);
void	get_elements(t_vars *vars, int fd);
int		render_next_rays(t_vars *vars);

// putin extras

int		putin_run(t_vars *g);
void	draw_putin(t_vars *vars, int i, t_ray *ray);
void	end_the_game(t_vars *vars, int suc);

// -------- dev -------

void	print_str_arr(char **input);

// ray the II 
void	draw_line(t_vars *vars, int i, t_ray *ray);
void	draw_wall(t_vars *vars, int i, int *j, t_ray *ray);
void	draw_field(t_vars *vars);
void	draw_putin_arays(t_vars *vars);
void	plot_line_angle(int start[2], float theta, float dist, t_vars *vars);
float	fix_fisheye_get_height(t_vars *vars, float distance, float angle_diff);
void	define_ray_parameters(t_vars *vars, t_ray *ray, float theta);

// new putin cast
void	cast_p_rays(t_vars *vars);
void	rotate_player(int keycode, t_vars *vars);

#endif