/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausanne.ch>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/23 16:24:35 by gkoller		   #+#	#+#			 */
/*   Updated: 2025/07/24 16:12:46 by lnicolos         ###   ####lausanne.ch   */
/*																			*/
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include "var.h"
# include "define.h"

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

# ifdef __APPLE__
#  include "../lib/mlx_mac/mlx.h"
# else
#  include "../lib/mlx_linux/mlx.h"
# endif
# include "../lib/libft/libft.h"

///check_map.c
int		check_map(t_var *var);
int		check_ligne(int	**map, t_coord size);

//check_rgb.c
int		check_rgb(char **str_rgb);

//collider.c
void	collider(t_var *var);

//create_map.c
int		create_map(t_var *var, char **sf_str, int start);

//filling_utils.c
int		ft_convert_color(char *str_color);
int		check_all_dup(char *str);

//filling_var.c
int		filling(t_var *var, const char *f_str);

//free_var.c
void	free_textures(t_var *var);
void	free_var(t_var *var);
void	clean_mlx(t_var *var);

//init_map.c
int		init_map(t_var *var, char *f_str);

//init_utils.c
int		ft_isspace(char c);
void	free_char_tab(char **str);
void	free_int_tab(int ***tab, int size_tab);
char	*del_space(char *c);

//init_var.c
void	init_var(t_var *var, char **f_str);

//init.c
int		init(t_var *var, const char	*path);
int		print_msg_err(int val_err, char **f_str);

//minimap.c
void	minimap_init(t_var *var);
void	minimap_free(t_var *var);
void	minimap_update(t_var *var);
void	minimap_print(t_var *var);

//event.c
int		key_press(int keycode, t_var *var);
int		key_release(int keycode, t_var *var);

//mlx_init.c
void	msg_error_mlx(t_var *var, int err);
int		close_window(t_var *var);
int		init_mlx(t_var *var);
int		loop(t_var *var);

//init_textures.c
int		check_textures(t_var *var);
int		init_textures(t_var *var);

//Player_mov.c
void	move_update(t_var *var);
void	move(t_var *var, int dir);

//print.c
void	affichage(t_var *var, t_ray ray);
void	pixel_put(t_mlx *mlx, int x, int y, int color);

//ray_utils.c
float	deg_to_rad(float deg);
void	init_dda_grid(t_dda *d, t_ray *r, t_var *v);
void	init_dda_step(t_dda *d, t_ray *r);
void	perform_dda(t_dda *d, t_var *v);

//ray.c
void	impact(t_ray *r, t_var *v);
int		raycast(t_var *var);

//textures.c
int		get_x_tex(t_ray ray);
int		get_tex_color(t_img *tex, int x, int y);
t_img	*get_texture(t_var *var, char face);

#endif
