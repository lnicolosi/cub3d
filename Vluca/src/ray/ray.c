/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolos <lnicolos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:02:54 by gkoller           #+#    #+#             */
/*   Updated: 2025/06/18 21:24:11 by lnicolos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/include.h"

static float	wall_dst(float	ray, float angle_player, float angle_ray)
{
	float	angle;
	float	len;

	angle = deg_to_rad(angle_ray - angle_player);
	len = ray * cosf(angle);
	return (fabsf(len));
}

static void impact(t_ray *ray, t_var *var)
{
	float dx, dy, l_ray = 0.0;
	t_coord cell, last;

	ray->dst = 0.0;
	last.x = (int)(var->player.pos_x / SIZESQUARE);
	last.y = (int)(var->player.pos_y / SIZESQUARE);

	while (l_ray < 10000)
	{
		dx = cosf(deg_to_rad(ray->angle)) * l_ray;
		dy = sinf(deg_to_rad(ray->angle)) * l_ray;

		cell.x = (int)((var->player.pos_x + dx) / SIZESQUARE);
		cell.y = (int)((var->player.pos_y + dy) / SIZESQUARE);

		if (var->map2d[cell.y][cell.x] == 1)
		{
			ray->dst = wall_dst(l_ray, var->player.a, ray->angle);
			if (ray->dst < 0.001)
				ray->dst = 0.001;

			if (cell.x != last.x)
				ray->face = (cell.x > last.x) ? 'W' : 'E';
			else
				ray->face = (cell.y > last.y) ? 'N' : 'S';
			break;
		}
		last = cell;
		l_ray += 0.05f;
	}
}



int raycast(t_var *var)
{
	int i = 0;
	t_ray ray;
	float angle_step = (float)FOV / (float)WIDTH;

	while (i < WIDTH)
	{
		ray.angle = var->player.a - (FOV / 2) + i * angle_step;
		ray.dir_x = cosf(deg_to_rad(ray.angle));
		ray.dir_y = sinf(deg_to_rad(ray.angle));
		impact(&ray, var);

		ray.col = 0.5;
		ray.num_ray = i;
		// if (i == WIDTH / 2)
		//     printf("Longeur = %f\n", ray.dst);
		affichage(var, ray);
		i++;
	}
	return (0);
}
