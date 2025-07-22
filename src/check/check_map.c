/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   check_map.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausanne.ch>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/05/17 10:09:32 by gkoller		   #+#	#+#			 */
/*   Updated: 2025/05/17 11:25:34 by gkoller		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../header/include.h"

static int	check_utils(int **map, int x, int y)
{
	map[y][x] = 2;
	return (1);
}

static int	check(int **map, t_coord size, int x, int y)
{
	int	check;

	check = 0;
	if (map[y][x] == 2)
	{
		if (y == 0 || y == size.y - 1 || x == 0 || x == size.x - 1)
			return (-7);
		if ((y > 0 && map[y - 1][x] == -1)
			|| (y < size.y - 1 && map[y + 1][x] == -1)
			|| (x > 0 && map[y][x - 1] == -1)
			|| (x < size.x - 1 && map[y][x + 1] == -1))
			return (-7);
		if (y > 0 && map[y - 1][x] == 0)
			check = check_utils(map, x, y - 1);
		if (y < size.y - 1 && map[y + 1][x] == 0)
			check = check_utils(map, x, y + 1);
		if (x > 0 && map[y][x - 1] == 0)
			check = check_utils(map, x - 1, y);
		if (x < size.x - 1 && map[y][x + 1] == 0)
			check = check_utils(map, x + 1, y);
	}
	return (check);
}

static void	raz_map(int **map, t_coord size)
{
	int	x;
	int	y;

	y = 0;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			if (map[y][x] == 2)
				map[y][x] = 0;
			x++;
		}
		y++;
	}
}

int	check_map(t_var *var)
{
	t_lvar	lvar;

	lvar.old_check = 1;
	var->map2d[var->player.pos.y][var->player.pos.x] = 2;
	while (lvar.old_check > 0)
	{
		lvar.y = 0;
		lvar.old_check = 0;
		while (lvar.y < var->size_map.y)
		{
			lvar.x = 0;
			while (lvar.x < var->size_map.x)
			{
				lvar.check = check(var->map2d, var->size_map, lvar.x, lvar.y);
				if (lvar.check < 0)
					return (lvar.check);
				if (lvar.check > 0)
					lvar.old_check += lvar.check;
				lvar.x++;
			}
			lvar.y++;
		}
	}
	raz_map(var->map2d, var->size_map);
	return (0);
}
