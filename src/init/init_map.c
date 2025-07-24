/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   init_map.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausanne.ch>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/05/16 12:35:54 by gkoller		   #+#	#+#			 */
/*   Updated: 2025/05/17 10:28:23 by gkoller		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../header/include.h"

static int	search_map(char **sf_str)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	while (sf_str[i])
	{
		j = 0;
		check = 0;
		while (sf_str[i][j])
		{
			if (sf_str[i][j] == '1' || ft_isspace(sf_str[i][j]))
				check = 1;
			else if (sf_str[i][j] != '1' || !ft_isspace(sf_str[i][j]))
			{
				check = 0;
				break ;
			}
			j++;
		}
		if (check == 1)
			return (i);
		i++;
	}
	return (-1);
}

static int	y_map(char **sf_str, int start)
{
	int	y;

	y = 0;
	while (sf_str[start - 1])
	{
		y++;
		start++;
	}
	return (y - 1);
}

static int	x_map(char **sf_str, int start)
{
	int	x;
	int	x_len;
	int	x_max;

	x_max = 0;
	while (sf_str[start])
	{
		x = 0;
		x_len = 0;
		while (sf_str[start][x])
		{
			if (sf_str[start][x] == '\t')
				x_len += 3;
			x++;
			x_len++;
		}
		if (x_len > x_max)
			x_max = x_len;
		start++;
	}
	return (x_max);
}

static int	alloc_map(int ***map2d, t_coord size_map)
{
	int	y;

	*map2d = (int **) malloc (sizeof(int *) * (size_map.y));
	if (!*map2d)
		return (-1);
	y = 0;
	while (y < size_map.y)
	{
		(*map2d)[y] = (int *) malloc (sizeof(int) * size_map.x);
		if (!(*map2d)[y])
		{
			while (--y >= 0)
				free((*map2d)[y]);
			free(*map2d);
			return (-1);
		}
		y++;
	}
	return (0);
}

int	init_map(t_var *var, char *f_str)
{
	t_map	map;

	map.check = 0;
	map.sf_str = ft_split(f_str, '\n');
	if (!map.sf_str)
		return (-6);
	map.start_line = search_map(map.sf_str);
	if (map.start_line > 0)
	{
		var->size_map.y = y_map(map.sf_str, map.start_line);
		if (var->size_map.y > 0)
			var->size_map.x = x_map(map.sf_str, map.start_line);
		if (var->size_map.x > 0)
			alloc_map(&(var->map2d), var->size_map);
	}
	else
		return (free_char_tab(map.sf_str), -6);
	if (create_map(var, map.sf_str, map.start_line) >= 0)
		map.check = check_map(var);
	else
		return (free_char_tab(map.sf_str), -7);
	free_char_tab(map.sf_str);
	if (!var->map2d)
		return (-6);
	return (map.check);
}
