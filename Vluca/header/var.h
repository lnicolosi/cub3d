/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   var.h											  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausanne.ch>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/24 11:46:18 by gkoller		   #+#	#+#			 */
/*   Updated: 2025/05/16 08:27:14 by gkoller		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef VAR_H
# define VAR_H

# include "include.h"

typedef struct s_var	t_var;
typedef struct s_player	t_player;
typedef struct s_coord	t_coord;
typedef struct s_lvar	t_lvar;
typedef struct s_mlx	t_mlx;
typedef struct s_ray	t_ray;
typedef struct s_img	t_img;

struct s_ray
{
	float		angle;
	int			num_ray;
	float		dst;
	char		face;
	float		col;
	float		dir_x;
	float		dir_y;
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

struct s_player
{
	int			x;//case
	int			y;//case
	float		pos_x;
	float		pos_y;
	float		a;
};

struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_lenght;
	int		endian;
	int		width;
	int		height;
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
	t_coord		size_map;
	t_player	player;
	t_mlx		mlx;
	t_img		t_no_img;
	t_img		t_so_img;
	t_img		t_ea_img;
	t_img		t_we_img;
};

#endif