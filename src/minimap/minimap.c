/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoller <gkoller@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:45:41 by gkoller           #+#    #+#             */
/*   Updated: 2025/06/30 17:37:24 by gkoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/include.h"

void	minimap_init(t_var *var)
{
	int	x;
	int	y;

	var->minimap = (int **) malloc (sizeof (int *) * var->size_map.y);
	y = 0;
	while (y < var->size_map.y)
	{
		x = 0;
		var->minimap[y] = (int *) malloc (sizeof (int) * var->size_map.x);
		while (x < var->size_map.x)
		{
			if (var->map2d[y][x] == 1)
				var->minimap[y][x] = COLOR_WALL;
			else if (var->map2d[y][x] == 0)
				var->minimap[y][x] = COLOR_FLOOR;
			else
				var->minimap[y][x] = -1;
			x++;
		}
		y++;
	}
	var->minimap[var->player.pos.y][var->player.pos.x] = COLOR_PLAYER;
	var->player.old_pos = var->player.pos;
}

void	minimap_free(t_var *var)
{
	int	y;

	y = 0;
	while (y < var->size_map.y)
	{
		free(var->minimap[y]);
		y++;
	}
	free(var->minimap);
}

void	minimap_update(t_var *var)
{
	if (var->player.old_pos.x != var->player.pos.x
		|| var->player.old_pos.y != var->player.pos.y)
	{
		var->minimap[var->player.old_pos.y]
		[var->player.old_pos.x] = COLOR_FLOOR;
		var->minimap[var->player.pos.y][var->player.pos.x] = COLOR_PLAYER;
		var->player.old_pos = var->player.pos;
	}
}

static void	minimap_while(t_var *var, t_mini *mini)
{
	mini->color = var->minimap[mini->y][mini->x];
	mini->py = 0;
	while (mini->py < mini->step_y)
	{
		mini->px = 0;
		while (mini->px < mini->step_x)
		{
			pixel_put(&var->mlx,
				mini->start_x + mini->x * mini->step_x + mini->px,
				mini->start_y + mini->y * mini->step_y + mini->py,
				mini->color);
			mini->px++;
		}
		mini->py++;
	}
}

void	minimap_print(t_var *var)
{
	t_mini	mini;

	mini.step_x = MINISIZE / var->size_map.x;
	mini.step_y = MINISIZE / var->size_map.y;
	mini.start_x = POS;
	mini.start_y = HEIGHT - POS - MINISIZE;
	mini.y = 0;
	while (mini.y < var->size_map.y)
	{
		mini.x = 0;
		while (mini.x < var->size_map.x)
		{
			minimap_while(var, &mini);
			mini.x++;
		}
		mini.y++;
	}
}
