/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolos <lnicolos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:17:03 by gkoller           #+#    #+#             */
/*   Updated: 2025/06/18 20:26:34 by lnicolos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/include.h"

// void pixel_put(t_mlx *mlx, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = mlx->addr + (y * mlx->line_lenght + x * (mlx->bits_per_pixel / 8));
// 	*(unsigned int *) dst = color;
// }

void pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char *dst;

    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;
    dst = mlx->addr + (y * mlx->line_lenght + x * (mlx->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

// void affichage(t_var *var, t_ray ray)
// {
//     int	wall_color = 0x00850606;
//     int	i;
//     int h_wall;
//     int h_ceilling;
//     float fov_rad = deg_to_rad(FOV);
//     float dist_proj = (WIDTH / 2.0f) / tanf(fov_rad / 2.0f);

//     if (ray.dst < 1.0f)
//         ray.dst = 1.0f;
//     h_wall = (int)((SIZESQUARE * dist_proj) / ray.dst);
//     if (h_wall > HEIGHT)
//         h_wall = HEIGHT;
//     h_ceilling = (HEIGHT - h_wall) / 2;
//     for (i = 0; i < HEIGHT; i++)
//     {
//         if (i < h_ceilling)
//             pixel_put(&var->mlx, ray.num_ray, i, var->f_color);
//         else if (i < (h_ceilling + h_wall))
//             pixel_put(&var->mlx, ray.num_ray, i, wall_color);
//         else
//             pixel_put(&var->mlx, ray.num_ray, i, var->c_color);
//     }
// }

int	get_x_tex(t_ray ray, t_var *var)
{
	float	hit_x, hit_y;

	hit_x = var->player.pos_x + cosf(deg_to_rad(ray.angle)) * ray.dst;
	hit_y = var->player.pos_y + sinf(deg_to_rad(ray.angle)) * ray.dst;

	if (ray.face == 'N' || ray.face == 'S')
		return ((int)hit_x % SIZESQUARE * 64 / SIZESQUARE);
	else
		return ((int)hit_y % SIZESQUARE * 64 / SIZESQUARE);
}


int	get_tex_color(t_img *tex, int x, int y)
{
	char	*dst;

	if (!tex || x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0xFF00FF); // rose debug

	dst = tex->addr + (y * tex->line_lenght + x * (tex->bpp / 8));
	return (*(unsigned int *)dst);
}


t_img	*get_texture(t_var *var, char face)
{
	if (face == 'N')
		return (&var->t_no_img);
	if (face == 'S')
		return (&var->t_so_img);
	if (face == 'E')
		return (&var->t_ea_img);
	if (face == 'W')
		return (&var->t_we_img);
	return (NULL);
}


void	affichage(t_var *var, t_ray ray)
{
	int		i;
	int		h_wall;
	int		h_ceilling;
	float	dist_proj;
	float	step;
	int		y_tex;
	t_img	*tex;

	dist_proj = (WIDTH / 2.0f) / tanf(deg_to_rad(FOV / 2));
	if (ray.dst < 1.0f)
		ray.dst = 1.0f;
	h_wall = (int)((SIZESQUARE * dist_proj) / ray.dst);
	if (h_wall > HEIGHT)
		h_wall = HEIGHT;
	h_ceilling = (HEIGHT - h_wall) / 2;
	step = 64.0f / (float)h_wall;

	tex = get_texture(var, ray.face); // fonction séparée

	i = 0;
	while (i < HEIGHT)
	{
		if (i < h_ceilling)
			pixel_put(&var->mlx, ray.num_ray, i, var->c_color);
		else if (i < h_ceilling + h_wall)
		{
			y_tex = (int)((i - h_ceilling) * step);
			pixel_put(&var->mlx, ray.num_ray, i,
				get_tex_color(tex, get_x_tex(ray, var), y_tex));
		}
		else
			pixel_put(&var->mlx, ray.num_ray, i, var->f_color);
		i++;
	}
}

