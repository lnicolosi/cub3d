/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolosi <lnicolosi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:45:01 by gkoller           #+#    #+#             */
/*   Updated: 2025/06/30 20:13:41 by lnicolosi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/include.h"

int	check_textures(t_var *var)
{
	if (!var->t_no_img.img || !var->t_so_img.img
		|| !var->t_ea_img.img || !var->t_we_img.img)
	{
		msg_error_mlx(var, 1);
		return (-4);
	}
	return (0);
}

void	check_first_texture(void *img, t_var *var)
{
	if (!img)
	{
		print_msg_err(-4, NULL);
		free_var(var);
		exit(EXIT_FAILURE);
	}
}

void	split_init_texture(t_var *var)
{
	var->t_so_img.addr = mlx_get_data_addr(var->t_so_img.img,
			&var->t_so_img.bpp,
			&var->t_so_img.line_lenght, &var->t_so_img.endian);
	var->t_ea_img.img = mlx_xpm_file_to_image(var->mlx.mlx,
			var->t_ea, &var->t_ea_img.width, &var->t_ea_img.height);
	check_first_texture(var->t_ea_img.img, var);
	var->t_ea_img.addr = mlx_get_data_addr(var->t_ea_img.img,
			&var->t_ea_img.bpp,
			&var->t_ea_img.line_lenght, &var->t_ea_img.endian);
	var->t_we_img.img = mlx_xpm_file_to_image(var->mlx.mlx,
			var->t_we, &var->t_we_img.width, &var->t_we_img.height);
	check_first_texture(var->t_we_img.img, var);
	var->t_we_img.addr = mlx_get_data_addr(var->t_we_img.img,
			&var->t_we_img.bpp,
			&var->t_we_img.line_lenght, &var->t_we_img.endian);
}

int	init_textures(t_var *var)
{
	var->t_no_img.img = mlx_xpm_file_to_image(var->mlx.mlx,
			var->t_no, &var->t_no_img.width, &var->t_no_img.height);
	check_first_texture(var->t_no_img.img, var);
	var->t_no_img.addr = mlx_get_data_addr(var->t_no_img.img,
			&var->t_no_img.bpp,
			&var->t_no_img.line_lenght, &var->t_no_img.endian);
	var->t_so_img.img = mlx_xpm_file_to_image(var->mlx.mlx,
			var->t_so, &var->t_so_img.width, &var->t_so_img.height);
	check_first_texture(var->t_so_img.img, var);
	split_init_texture(var);
	if (check_textures(var) < 0)
	{
		free_var(var);
		return (-4);
	}
	return (0);
}
