/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolosi <lnicolosi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:02:21 by gkoller           #+#    #+#             */
/*   Updated: 2025/06/30 20:11:12 by lnicolosi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VAR_H
# define VAR_H

# include "include.h"

typedef struct s_map			t_map;
typedef struct s_print			t_print;
typedef struct s_keys			t_keys;
typedef struct s_mini			t_mini;
typedef struct s_var			t_var;
typedef struct s_player			t_player;
typedef struct s_allowed_mov	t_allow_mov;
typedef struct s_coord			t_coord;
typedef struct s_lvar			t_lvar;
typedef struct s_mlx			t_mlx;
typedef struct s_ray			t_ray;
typedef struct s_img			t_img;
typedef struct s_dda			t_dda;

struct s_map
{
	char	**sf_str;
	int		start_line;
	int		check;
};

struct s_print
{
	int			tex_x;
	float		wall_x;
	int			i;
	int			h_wall;
	int			h_ceilling;
	float		dist_proj;
	float		step;
	int			y_tex;
	t_img		*tex;
};

struct s_keys
{
	int			w;
	int			s;
	int			a;
	int			d;
	int			left;
	int			right;
};

struct s_mini
{
	int			x;
	int			y;
	int			px;
	int			py;
	int			color;
	int			step_x;
	int			step_y;
	int			start_x;
	int			start_y;
};

struct s_ray
{
	float		angle;
	int			num_ray;
	float		dst;
	char		face;
	float		dir_x;
	float		dir_y;
	int			impact_x;
	int			impact_y;
};

struct s_lvar
{
	int			check;
	int			old_check;
	int			x;
	int			y;
};

struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_lenght;
	int			endian;
};

struct s_coord
{
	int			x;
	int			y;
};

struct s_allowed_mov
{
	int			up;
	int			down;
	int			left;
	int			right;
};

struct s_player
{
	t_coord		pos;
	t_coord		old_pos;
	float		pos_x;
	float		pos_y;
	float		a;
	int			nb;
};

struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_lenght;
	int			endian;
	int			width;
	int			height;
};

struct s_dda
{
	t_coord		map;
	float		p_grid_x;
	float		p_grid_y;
	float		d_dist_x;
	float		d_dist_y;
	float		s_dist_x;
	float		s_dist_y;
	int			step_x;
	int			step_y;
	int			side;
};

struct s_var
{
	char		*t_no;
	char		*t_so;
	char		*t_ea;
	char		*t_we;
	int			f_color;
	int			c_color;
	int			**map2d;
	int			**minimap;
	t_keys		keys;
	t_coord		size_map;
	t_player	player;
	t_allow_mov	mov;
	t_mlx		mlx;
	t_img		t_no_img;
	t_img		t_so_img;
	t_img		t_ea_img;
	t_img		t_we_img;
};

#endif