/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   include.h										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausanne.ch>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/23 16:24:35 by gkoller		   #+#	#+#			 */
/*   Updated: 2025/05/16 08:30:31 by gkoller		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

# include "../lib/libft/libft.h"
# include "../lib/mlx_linux/mlx.h"

# include "var.h"
# include "define.h"

//init.c
int		init(t_var *var, const char	*path);
int		print_msg_err(int val_err, char **f_str);

//free_var.c
void	init_var(t_var *var, char **f_str);
void	free_var(t_var *var);

void	print_map(t_var *var);//a suprimmer
void	print_var(t_var *var);

//filling_var.c
int		filling(t_var *var, const char *f_str);

//filling_utils.c
int		ft_convert_color(char *str_color);

//init_map.c
int		init_map(t_var *var, char *f_str);

//create_map.c
int		create_map(t_var *var, char **sf_str, int start);

//check_map.c
int		check_map(t_var *var);

//utils.c
int		ft_isspace(char c);
void	free_char_tab(char **str);
void	free_int_tab(int ***tab, int size_tab);

//mlx_init.c
int		close_window(t_var *var);
int		init_mlx(t_var *var);
int		loop(t_var *var);

//event.c
int		event(int keycode, t_var *var);

//ray.c
int		raycast(t_var *var);

//ray_utils.c
float	deg_to_rad(int deg);

//Player_mov.c
void	move(t_var *var, int dir);

//print.c
void affichage(t_var *var, t_ray ray);

#endif