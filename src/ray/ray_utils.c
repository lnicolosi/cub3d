/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoller <gkoller@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 07:23:27 by gkoller           #+#    #+#             */
/*   Updated: 2025/06/25 15:00:45 by gkoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/include.h"

float	deg_to_rad(float deg)
{
	float	rad;

	rad = deg * (PI / 180);
	return (rad);
}

void	init_dda_grid(t_dda *d, t_ray *r, t_var *v)
{
	d->p_grid_x = v->player.pos_x / SIZESQUARE;
	d->p_grid_y = v->player.pos_y / SIZESQUARE;
	d->map.x = (int)d->p_grid_x;
	d->map.y = (int)d->p_grid_y;
	if (r->dir_x == 0)
		d->d_dist_x = 1e30;
	else
		d->d_dist_x = fabsf(1 / r->dir_x);
	if (r->dir_y == 0)
		d->d_dist_y = 1e30;
	else
		d->d_dist_y = fabsf(1 / r->dir_y);
}

void	init_dda_step(t_dda *d, t_ray *r)
{
	if (r->dir_x < 0)
	{
		d->step_x = -1;
		d->s_dist_x = (d->p_grid_x - d->map.x) * d->d_dist_x;
	}
	else
	{
		d->step_x = 1;
		d->s_dist_x = (d->map.x + 1.0 - d->p_grid_x) * d->d_dist_x;
	}
	if (r->dir_y < 0)
	{
		d->step_y = -1;
		d->s_dist_y = (d->p_grid_y - d->map.y) * d->d_dist_y;
	}
	else
	{
		d->step_y = 1;
		d->s_dist_y = (d->map.y + 1.0 - d->p_grid_y) * d->d_dist_y;
	}
}

void	perform_dda(t_dda *d, t_var *v)
{
	while (1)
	{
		if (d->s_dist_x < d->s_dist_y)
		{
			d->s_dist_x += d->d_dist_x;
			d->map.x += d->step_x;
			d->side = 0;
		}
		else
		{
			d->s_dist_y += d->d_dist_y;
			d->map.y += d->step_y;
			d->side = 1;
		}
		if (v->map2d[d->map.y][d->map.x] == 1)
			return ;
	}
}
