/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoller <gkoller@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:17:03 by gkoller           #+#    #+#             */
/*   Updated: 2025/06/30 16:25:21 by gkoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/include.h"

void	pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (!mlx->addr)
		return ;
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = mlx->addr + (y * mlx->line_lenght + x * (mlx->bits_per_pixel / 8));
	if (color != COLOR_TRANS)
		*(unsigned int *)dst = color;
}

void	affichage(t_var *var, t_ray ray)
{
	t_print	print;

	print.dist_proj = (WIDTH / 2.0f) / tanf(deg_to_rad(FOV / 2));
	if (ray.dst < 1.0f)
		ray.dst = 1.0f;
	print.h_wall = (int)((SIZESQUARE * print.dist_proj) / ray.dst);
	print.h_ceilling = (HEIGHT - print.h_wall) / 2;
	print.step = 64.0f / (float)print.h_wall;
	print.tex = get_texture(var, ray.face);
	print.i = 0;
	while (++print.i < HEIGHT)
	{
		if (print.i < print.h_ceilling)
			pixel_put(&var->mlx, ray.num_ray, print.i, var->c_color);
		else if (print.i < print.h_ceilling + print.h_wall)
		{
			print.y_tex = (int)((print.i - print.h_ceilling) * print.step);
			pixel_put(&var->mlx, ray.num_ray, print.i,
				get_tex_color(print.tex, get_x_tex(ray), print.y_tex));
		}
		else
			pixel_put(&var->mlx, ray.num_ray, print.i, var->f_color);
	}
}
