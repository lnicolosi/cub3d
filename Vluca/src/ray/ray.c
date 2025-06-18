/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoller <gkoller@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:02:54 by gkoller           #+#    #+#             */
/*   Updated: 2025/05/21 16:26:58 by gkoller          ###   ########.fr       */
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
    t_coord cell;

    ray->dst = 0.0;
    while (l_ray < 10000)
    {
        dx = cosf(deg_to_rad(ray->angle)) * l_ray;
        dy = sinf(deg_to_rad(ray->angle)) * l_ray;
        cell.x = (var->player.pos_x + dx) / SIZESQUARE;
        cell.y = (var->player.pos_y + dy) / SIZESQUARE;
        if (var->map2d[cell.y][cell.x] == 1)
        {
            ray->dst = wall_dst(l_ray, var->player.a, ray->angle);
            if (ray->dst < 0.001)
                ray->dst = 0.001;
            break;
        }
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
		impact(&ray, var);
		ray.face = 'N';
		ray.col = 0.5;
		ray.num_ray = i;
		// if (i == WIDTH / 2)
		//     printf("Longeur = %f\n", ray.dst);
		affichage(var, ray);
		i++;
	}
	return (0);
}
