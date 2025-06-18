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

static int	check_rgb(char **str_rgb)
{
	int	len;
	int	i;
	int	j;

	len = 0;
	while (str_rgb[len])
		len++;
	if (len != 3)
		return (-1);
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (str_rgb[i][j])
		{
			if (str_rgb[i][j] < '0' || str_rgb[i][j] > '9')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_convert_color(char *str_color)
{
	char	**str_rgb;
	int		color;
	int		rgb[3];

	str_rgb = ft_split(str_color, ',');
	if (!str_rgb)
		return (-1);
	if (check_rgb(str_rgb) < 0)
		return (free_char_tab(str_rgb), -1);
	rgb[0] = ft_atoi(str_rgb[0]);
	rgb[1] = ft_atoi(str_rgb[1]);
	rgb[2] = ft_atoi(str_rgb[2]);
	if (rgb[0] < 0 || rgb[0] > 255 || rgb[1] < 0
		|| rgb[1] > 255 || rgb[2] < 0 || rgb[2] > 255)
		return (free_char_tab(str_rgb), -1);
	color = rgb[2] + (rgb[1] << 8) + (rgb[0] << 16);
	free_char_tab(str_rgb);
	return (color);
}
