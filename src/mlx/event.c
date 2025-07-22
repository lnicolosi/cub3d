/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoller <gkoller@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:33:25 by gkoller           #+#    #+#             */
/*   Updated: 2025/06/25 14:44:36 by gkoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/include.h"

int	key_press(int keycode, t_var *var)
{
	if (keycode == ESC)
		close_window(var);
	if (keycode == UP)
		var->keys.w = 1;
	if (keycode == DOWN)
		var->keys.s = 1;
	if (keycode == LEFT)
		var->keys.a = 1;
	if (keycode == RIGHT)
		var->keys.d = 1;
	if (keycode == F_LEFT)
		var->keys.left = 1;
	if (keycode == F_RIGHT)
		var->keys.right = 1;
	return (0);
}

int	key_release(int keycode, t_var *var)
{
	if (keycode == UP)
		var->keys.w = 0;
	if (keycode == DOWN)
		var->keys.s = 0;
	if (keycode == LEFT)
		var->keys.a = 0;
	if (keycode == RIGHT)
		var->keys.d = 0;
	if (keycode == F_LEFT)
		var->keys.left = 0;
	if (keycode == F_RIGHT)
		var->keys.right = 0;
	return (0);
}
