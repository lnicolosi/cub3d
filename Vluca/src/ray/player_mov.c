/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoller <gkoller@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 14:37:45 by gkoller           #+#    #+#             */
/*   Updated: 2025/05/21 16:19:18 by gkoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/include.h"

// static int collider(t_var *var, int dir)
// {
// 	float	dx;
// 	float	dy;
// 	int		i;
// 	t_coord	cell;

// 	i = (FOV / 2) * -1;
// 	while (i < (FOV / 2))
// 	{
// 		dx = sinf(deg_to_rad (i + var->player.a + dir)) * DST_COL;
// 		dy = cosf(deg_to_rad (i + var->player.a + dir)) * DST_COL;
// 		cell.x = (var->player.pos_x - dx) / SIZESQUARE;
// 		cell.y = (var->player.pos_y - dy) / SIZESQUARE;
// 		if (var->map2d[cell.y][cell.x] == 1)
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

void move(t_var *var, int dir)
{
    if (dir == UP)
    {
        var->player.pos_x += (int)(cosf(deg_to_rad(var->player.a)) * SPEED);
        var->player.pos_y += (int)(sinf(deg_to_rad(var->player.a)) * SPEED);
    }
    if (dir == DOWN)
    {
        var->player.pos_x -= (int)(cosf(deg_to_rad(var->player.a)) * SPEED);
        var->player.pos_y -= (int)(sinf(deg_to_rad(var->player.a)) * SPEED);
    }
    if (dir == LEFT) // strafe gauche
    {
        var->player.pos_x += (int)(cosf(deg_to_rad(var->player.a - 90)) * SPEED);
        var->player.pos_y += (int)(sinf(deg_to_rad(var->player.a - 90)) * SPEED);
    }
    if (dir == RIGHT) // strafe droite
    {
        var->player.pos_x += (int)(cosf(deg_to_rad(var->player.a + 90)) * SPEED);
        var->player.pos_y += (int)(sinf(deg_to_rad(var->player.a + 90)) * SPEED);
    }
}
