/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoller <gkoller@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 15:02:54 by gkoller           #+#    #+#             */
/*   Updated: 2025/06/29 21:19:11 by gkoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/include.h"

void	impact(t_ray *r, t_var *v)
{
	t_dda	d;

	init_dda_grid(&d, r, v);
	init_dda_step(&d, r);
	perform_dda(&d, v);
	if (d.side == 0)
		r->dst = (d.map.x - d.p_grid_x + (1 - d.step_x) / 2.0f) / r->dir_x;
	else
		r->dst = (d.map.y - d.p_grid_y + (1 - d.step_y) / 2.0f) / r->dir_y;
	r->impact_x = (int)(v->player.pos_x + r->dst * r->dir_x * SIZESQUARE);
	r->impact_y = (int)(v->player.pos_y + r->dst * r->dir_y * SIZESQUARE);
	if (d.side == 0)
	{
		if (r->dir_x > 0)
			r->face = 'W';
		else
			r->face = 'E';
	}
	else
	{
		if (r->dir_y > 0)
			r->face = 'N';
		else
			r->face = 'S';
	}
}

int	raycast(t_var *var)
{
	int		i;
	t_ray	ray;
	float	angle_step;
	float	corrected;

	angle_step = (float)FOV / (float)WIDTH;
	i = 0;
	while (i < WIDTH)
	{
		ray.angle = var->player.a - (FOV / 2) + i * angle_step;
		ray.dir_x = cosf(deg_to_rad(ray.angle));
		ray.dir_y = sinf(deg_to_rad(ray.angle));
		impact(&ray, var);
		corrected = ray.dst * cosf(deg_to_rad(ray.angle - var->player.a));
		ray.dst = corrected;
		ray.num_ray = i;
		ray.dst *= SIZESQUARE;
		affichage(var, ray);
		i++;
	}
	return (0);
}
