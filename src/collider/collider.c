/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collider.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoller <gkoller@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:39:49 by gkoller           #+#    #+#             */
/*   Updated: 2025/06/23 15:08:35 by gkoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/include.h"

static int	check_case(t_var *var, float dx, float dy)
{
	int	x;
	int	y;

	x = (int)dx / SIZESQUARE;
	y = (int)dy / SIZESQUARE;
	if (x < 0 || x >= var->size_map.x || y < 0 || y >= var->size_map.y)
		return (1);
	return (var->map2d[y][x]);
}

static void	raz_mov(t_var *var)
{
	var->mov.up = 0;
	var->mov.down = 0;
	var->mov.left = 0;
	var->mov.right = 0;
}

void	collider(t_var *var)
{
	raz_mov(var);
	if (check_case(var,
			var->player.pos_x + cosf(deg_to_rad(var->player.a)) * DST_COL,
			var->player.pos_y + sinf(deg_to_rad(var->player.a)) * DST_COL))
		var->mov.up = 1;
	if (check_case(var,
			var->player.pos_x - cosf(deg_to_rad(var->player.a)) * DST_COL,
			var->player.pos_y - sinf(deg_to_rad(var->player.a)) * DST_COL))
		var->mov.down = 1;
	if (check_case(var,
			var->player.pos_x + cosf(deg_to_rad(var->player.a - 90)) * DST_COL,
			var->player.pos_y + sinf(deg_to_rad(var->player.a - 90)) * DST_COL))
		var->mov.left = 1;
	if (check_case(var,
			var->player.pos_x + cosf(deg_to_rad(var->player.a + 90)) * DST_COL,
			var->player.pos_y + sinf(deg_to_rad(var->player.a + 90)) * DST_COL))
		var->mov.right = 1;
}
