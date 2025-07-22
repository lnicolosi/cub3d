/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoller <gkoller@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:37:45 by gkoller           #+#    #+#             */
/*   Updated: 2025/06/25 14:22:30 by gkoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/include.h"

void	move_update(t_var *var)
{
	if (var->keys.w)
		move(var, UP);
	if (var->keys.s)
		move(var, DOWN);
	if (var->keys.a)
		move(var, LEFT);
	if (var->keys.d)
		move(var, RIGHT);
	if (var->keys.left)
		var->player.a -= ROT_SPEED;
	if (var->keys.right)
		var->player.a += ROT_SPEED;
	if (var->player.a < 0)
		var->player.a += 360.0f;
	if (var->player.a >= 360.0f)
		var->player.a -= 360.0f;
}

static void	move_next(t_var *var, int dir)
{
	if (dir == LEFT && var->mov.left == 0)
	{
		var->player.pos_x += (int)
			(cosf(deg_to_rad(var->player.a - 90)) * SPEED);
		var->player.pos_y += (int)
			(sinf(deg_to_rad(var->player.a - 90)) * SPEED);
	}
	if (dir == RIGHT && var->mov.right == 0)
	{
		var->player.pos_x += (int)
			(cosf(deg_to_rad(var->player.a + 90)) * SPEED);
		var->player.pos_y += (int)
			(sinf(deg_to_rad(var->player.a + 90)) * SPEED);
	}
	var->player.pos.x = (int) var->player.pos_x / 64;
	var->player.pos.y = (int) var->player.pos_y / 64;
}

void	move(t_var *var, int dir)
{
	float	angle;

	angle = deg_to_rad(var->player.a);
	if (dir == UP && var->mov.up == 0)
	{
		var->player.pos_x += (int)(cosf(angle) * SPEED);
		var->player.pos_y += (int)(sinf(angle) * SPEED);
	}
	if (dir == DOWN && var->mov.down == 0)
	{
		var->player.pos_x -= (int)(cosf(angle) * SPEED);
		var->player.pos_y -= (int)(sinf(angle) * SPEED);
	}
	move_next(var, dir);
}
