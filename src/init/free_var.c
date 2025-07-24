/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   free_var.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausanne.ch>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/05/16 10:27:49 by gkoller		   #+#	#+#			 */
/*   Updated: 2025/05/16 11:43:15 by gkoller		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../header/include.h"

void	free_textures(t_var *var)
{
	if (var->t_no_img.img)
		mlx_destroy_image(var->mlx.mlx, var->t_no_img.img);
	if (var->t_so_img.img)
		mlx_destroy_image(var->mlx.mlx, var->t_so_img.img);
	if (var->t_we_img.img)
		mlx_destroy_image(var->mlx.mlx, var->t_we_img.img);
	if (var->t_ea_img.img)
		mlx_destroy_image(var->mlx.mlx, var->t_ea_img.img);
}

void	clean_mlx(t_var *var)
{
	if (!var)
		return ;
	if (var->mlx.img)
		mlx_destroy_image(var->mlx.mlx, var->mlx.img);
	if (var->mlx.mlx_win)
		mlx_destroy_window(var->mlx.mlx, var->mlx.mlx_win);
	if (var->mlx.mlx)
	{
		mlx_destroy_display(var->mlx.mlx);
		free(var->mlx.mlx);
	}
}

void	free_var(t_var *var)
{
	if (var->t_no)
		free(var->t_no);
	if (var->t_so)
		free(var->t_so);
	if (var->t_ea)
		free(var->t_ea);
	if (var->t_we)
		free(var->t_we);
	var->t_no = NULL;
	var->t_so = NULL;
	var->t_ea = NULL;
	var->t_we = NULL;
	if (var->map2d)
		free_int_tab(&(var->map2d), var->size_map.y);
	if (var->minimap)
		minimap_free(var);
	free_textures(var);
	clean_mlx(var);
}
