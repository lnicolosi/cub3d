/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   filling_utils.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausanne.ch>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/05/16 12:22:53 by gkoller		   #+#	#+#			 */
/*   Updated: 2025/05/16 12:25:58 by gkoller		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../header/include.h"

int	ft_convert_color(char *str_color)
{
	char	**str_rgb;
	int		rgb[3];
	int		color;

	str_rgb = ft_split(str_color, ',');
	if (!str_rgb)
		return (-1);
	if (check_rgb(str_rgb) < 0)
		return (free_char_tab(str_rgb), -1);
	rgb[0] = ft_atoi(str_rgb[0]);
	rgb[1] = ft_atoi(str_rgb[1]);
	rgb[2] = ft_atoi(str_rgb[2]);
	free_char_tab(str_rgb);
	if (rgb[0] < 0 || rgb[0] > 255
		|| rgb[1] < 0 || rgb[1] > 255
		|| rgb[2] < 0 || rgb[2] > 255)
		return (-1);
	color = (rgb[0] << 16) + (rgb[1] << 8) + rgb[2];
	return (color);
}

int	check_dup(const char *str, const char *id)
{
	char	**lines;
	int		i;
	int		count;
	size_t	id_len;

	lines = ft_split(str, '\n');
	if (!lines)
		return (0);
	i = 0;
	count = 0;
	id_len = ft_strlen(id);
	while (lines[i])
	{
		if (ft_strncmp(lines[i], id, id_len) == 0
			&& ft_isspace((unsigned char)lines[i][id_len]))
			count++;
		i++;
	}
	free_char_tab(lines);
	return (count > 1);
}

int	check_all_dup(char *str)
{
	if (check_dup(str, "NO")
		|| check_dup(str, "SO")
		|| check_dup(str, "WE")
		|| check_dup(str, "EA"))
		return (-4);
	if (check_dup(str, "F") || check_dup(str, "C"))
		return (-5);
	return (0);
}
