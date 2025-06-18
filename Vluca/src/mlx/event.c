/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoller <gkoller@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:33:25 by gkoller           #+#    #+#             */
/*   Updated: 2025/05/21 16:31:51 by gkoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/include.h"

int event(int keycode, t_var *var)
{
	//printf("Key Code = %d\n", keycode);
	if (keycode == ESC)
	{
		//mlx_destroy_window (var->mlx.mlx, var->mlx.mlx_win);
		close_window(var);
	}
	if (keycode == UP)
		move(var, UP);
	if (keycode == DOWN)
		move(var, DOWN);
	if (keycode == LEFT)
		move(var, LEFT);
	if (keycode == RIGHT)
		move(var, RIGHT);
	if (keycode == F_LEFT)
		var->player.a -= ROT_SPEED;
	if (keycode == F_RIGHT)
		var->player.a += ROT_SPEED;
	if (var->player.a < 0)
		var->player.a += 360.0f;
	if (var->player.a >= 360.0f)
		var->player.a -= 360.0f;
	return (0);
}
