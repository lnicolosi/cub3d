/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolos <lnicolos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:19:02 by gkoller           #+#    #+#             */
/*   Updated: 2025/07/18 17:55:13 by lnicolos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/include.h"

void	msg_error_mlx(t_var *var, int err)
{
	if (err == 1)
	{
		printf("Erreur: une ou plusieurs textures sont invalides\n");
		free_var(var);
		exit(1);
	}
	if (err == 2)
	{
		printf("Erreur: mlx_init() a échoué\n");
		exit(1);
	}
	if (err == 3)
	{
		printf("Erreur: mlx_new_image a échoué\n");
		exit(1);
	}
	if (err == 4)
	{
		printf("Erreur: mlx_get_data_addr a échoué\n");
		exit(1);
	}
}

int	close_window(t_var *var)
{
	free_var(var);
	free_textures(var);
	clean_mlx(var);
	exit(0);
	return (0);
}

int	init_mlx(t_var *var)
{
	var->mlx.mlx = mlx_init();
	if (!var->mlx.mlx)
		msg_error_mlx(var, 2);
	init_textures(var);
	var->mlx.mlx_win = mlx_new_window(var->mlx.mlx, WIDTH, HEIGHT, "cub3D");
	var->mlx.img = mlx_new_image(var->mlx.mlx, WIDTH, HEIGHT);
	if (!var->mlx.img)
		msg_error_mlx(var, 3);
	var->mlx.addr = mlx_get_data_addr(var->mlx.img, &var->mlx.bits_per_pixel,
			&var->mlx.line_lenght, &var->mlx.endian);
	if (!var->mlx.addr)
		msg_error_mlx(var, 4);
	mlx_hook(var->mlx.mlx_win, 17, 0, close_window, var);
	mlx_hook(var->mlx.mlx_win, 2, 1L << 0, key_press, var);
	mlx_hook(var->mlx.mlx_win, 3, 1L << 1, key_release, var);
	mlx_loop_hook(var->mlx.mlx, loop, var);
	mlx_loop (var->mlx.mlx);
	return (0);
}

int	loop(t_var *var)
{
	collider(var);
	move_update(var);
	raycast(var);
	minimap_update(var);
	minimap_print(var);
	mlx_put_image_to_window (var->mlx.mlx,
		var->mlx.mlx_win, var->mlx.img, 0, 0);
	return (0);
}
