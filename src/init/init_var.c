/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolos <lnicolos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:10:11 by gkoller           #+#    #+#             */
/*   Updated: 2025/07/18 18:03:49 by lnicolos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/include.h"

static void	init_var_next(t_var *var)
{
	var->keys.w = 0;
	var->keys.s = 0;
	var->keys.a = 0;
	var->keys.d = 0;
	var->keys.left = 0;
	var->keys.right = 0;
	var->t_no_img.img = NULL;
	var->t_so_img.img = NULL;
	var->t_ea_img.img = NULL;
	var->t_we_img.img = NULL;
}

void	init_var(t_var *var, char **f_str)
{
	var->t_no = NULL;
	var->t_so = NULL;
	var->t_ea = NULL;
	var->t_we = NULL;
	*f_str = NULL;
	var->map2d = NULL;
	var->size_map.y = 0;
	var->size_map.x = 0;
	var->player.pos.x = 0;
	var->player.pos.y = 0;
	var->player.old_pos.x = 0;
	var->player.old_pos.y = 0;
	var->player.a = 0;
	var->player.nb = 0;
	var->mov.up = 0;
	var->mov.down = 0;
	var->mov.left = 0;
	var->mov.right = 0;
	var->minimap = NULL;
	init_var_next(var);
}
