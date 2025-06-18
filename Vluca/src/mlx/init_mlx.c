/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolos <lnicolos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:19:02 by gkoller           #+#    #+#             */
/*   Updated: 2025/06/18 20:02:01 by lnicolos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/include.h"

int	close_window(t_var *var)
{
	free_var(var);
	exit(0);
	return (0);
}

void	init_textures(t_var *var)
{
	var->t_no_img.img = mlx_xpm_file_to_image(var->mlx.mlx,
			var->t_no, &var->t_no_img.width, &var->t_no_img.height);
	var->t_no_img.addr = mlx_get_data_addr(var->t_no_img.img,
			&var->t_no_img.bpp,
			&var->t_no_img.line_lenght, &var->t_no_img.endian);
	var->t_so_img.img = mlx_xpm_file_to_image(var->mlx.mlx,
			var->t_so,
			&var->t_so_img.width, &var->t_so_img.height);
	var->t_so_img.addr = mlx_get_data_addr(var->t_so_img.img,
			&var->t_so_img.bpp,
			&var->t_so_img.line_lenght, &var->t_so_img.endian);
	var->t_ea_img.img = mlx_xpm_file_to_image(var->mlx.mlx,
			var->t_ea, &var->t_ea_img.width, &var->t_ea_img.height);
	var->t_ea_img.addr = mlx_get_data_addr(var->t_ea_img.img,
			&var->t_ea_img.bpp,
			&var->t_ea_img.line_lenght, &var->t_ea_img.endian);
	var->t_we_img.img = mlx_xpm_file_to_image(var->mlx.mlx,
			var->t_we, &var->t_we_img.width, &var->t_we_img.height);
	var->t_we_img.addr = mlx_get_data_addr(var->t_we_img.img,
			&var->t_we_img.bpp,
			&var->t_we_img.line_lenght, &var->t_we_img.endian);
}

void	check_textures(t_var *var)
{
	if (!var->t_no_img.img || !var->t_so_img.img
		|| !var->t_ea_img.img || !var->t_we_img.img)
	{
		printf("Erreur: une ou plusieurs textures sont invalides\n");
		free_var(var);
		exit(1);
	}
}


int	init_mlx(t_var *var)
{
	var->mlx.mlx = mlx_init();
	init_textures(var);
	check_textures(var);
	var->mlx.mlx_win = mlx_new_window(var->mlx.mlx, WIDTH, HEIGHT, "cub3D");
	var->mlx.img = mlx_new_image(var->mlx.mlx, WIDTH, HEIGHT);
	if (!var->mlx.img)
	{
		printf("Erreur: mlx_new_image a échoué\n");
		exit(1);
	}
	var->mlx.addr = mlx_get_data_addr(var->mlx.img, &var->mlx.bits_per_pixel,
			&var->mlx.line_lenght, &var->mlx.endian);
	if (!var->mlx.addr)
	{
		printf("Erreur: mlx_get_data_addr a échoué\n");
		exit(1);
	}
	mlx_hook(var->mlx.mlx_win, 17, 0, close_window, var);
	mlx_hook(var->mlx.mlx_win, 2, 1L << 0, event, var);
	mlx_loop_hook(var->mlx.mlx, loop, var);
	mlx_loop (var->mlx.mlx);
	return (0);
}

int	loop(t_var *var)
{
	raycast(var);
	mlx_put_image_to_window (var->mlx.mlx, var->mlx.mlx_win, var->mlx.img, 0, 0);
	return (0);
}
