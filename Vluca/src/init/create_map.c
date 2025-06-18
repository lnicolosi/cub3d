/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   create_map.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausanne.ch>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/05/16 14:35:24 by gkoller		   #+#	#+#			 */
/*   Updated: 2025/05/17 10:45:40 by gkoller		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../header/include.h"

static void	zero_map(t_var *var)
{
	int	y;
	int	x;

	y = 0;
	while (y < var->size_map.y)
	{
		x = 0;
		while (x < var->size_map.x)
		{
			var->map2d[y][x] = 0;
			x++;
		}
		y++;
	}
}

static int	val_map(t_var *var, int pos[], int c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		var->player.x = pos[2];
		var->player.y = pos[0];
		var->player.pos_x = (var->player.x * SIZESQUARE) + (SIZESQUARE / 2) - 1;
		var->player.pos_y = (var->player.y * SIZESQUARE) + (SIZESQUARE / 2) - 1;
		if (c == 'N')
			var->player.a = 270.0f;
		if (c == 'S')
			var->player.a = 90;
		if (c == 'E')
			var->player.a = 180;
		if (c == 'W')
			var->player.a = 0;
	}
	if (c == '1')
		var->map2d[pos[0]][pos[2]] = 1;
	if (c != 'N' && c != 'S' && c != 'E' && c != 'W'
		&& c != '0' && c != '1' && !ft_isspace(c))
		return (-1);
	return (0);
}

int	create_map(t_var *var, char **sf_str, int start)
{
	int	pos[3];

	zero_map(var);
	pos[0] = 0;
	while (sf_str[start + pos[0]])
	{
		pos[1] = 0;
		pos[2] = 0;
		while (pos[2] < var->size_map.x && sf_str[start + pos[0]][pos[1]])
		{
			if (val_map(var, pos, sf_str[start + pos[0]][pos[1]]) < 0)
				return (-1);
			if (sf_str[start + pos[0]][pos[1]] == '\t')
				pos[2] += 3;
			pos[2]++;
			if (pos[2] > var->size_map.x)
				pos[2] = var->size_map.x;
			pos[1]++;
		}
		pos[0]++;
	}
	return (0);
}
