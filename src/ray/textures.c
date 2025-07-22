/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoller <gkoller@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:59:55 by gkoller           #+#    #+#             */
/*   Updated: 2025/06/29 21:29:54 by gkoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/include.h"

int	get_x_tex(t_ray ray)
{
	if (ray.face == 'N' || ray.face == 'S')
		return (ray.impact_x % SIZESQUARE * 64 / SIZESQUARE);
	else
		return (ray.impact_y % SIZESQUARE * 64 / SIZESQUARE);
}

int	get_tex_color(t_img *tex, int x, int y)
{
	char	*dst;

	if (!tex || x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0xFF00FF);
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
