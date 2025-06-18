/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   filling_var.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausanne.ch>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/05/16 09:31:44 by gkoller		   #+#	#+#			 */
/*   Updated: 2025/05/16 11:34:07 by gkoller		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../header/include.h"

static int	f_texture(t_var *var, char *texture_path, char *texture_str)
{
	if (!ft_strncmp(texture_str, "NO", 2))
	{
		var->t_no = ft_strdup(texture_path);
		if (var->t_no != NULL)
			return (0);
	}
	if (!ft_strncmp(texture_str, "SO", 2))
	{
		var->t_so = ft_strdup(texture_path);
		if (var->t_so != NULL)
			return (0);
	}
	if (!ft_strncmp(texture_str, "EA", 2))
	{
		var->t_ea = ft_strdup(texture_path);
		if (var->t_ea != NULL)
			return (0);
	}
	if (!ft_strncmp(texture_str, "WE", 2))
	{
		var->t_we = ft_strdup(texture_path);
		if (var->t_we != NULL)
			return (0);
	}
	return (-1);
}

static int	filling_texture(t_var *var, const char *f_str, char *texture_str)
{
	char	*c;
	int		len;
	char	*temp;
	int		val_err;

	val_err = 0;
	c = ft_strnstr(f_str, texture_str, ft_strlen(f_str));
	if (c != NULL)
	{
		c += 2;
		while (ft_isspace(*c))
			c++;
		len = 0;
		while (c[len] && !ft_isspace(c[len]))
			len++;
		temp = (char *) malloc (sizeof(char) * (len + 1));
		if (!temp)
			return (-2);
		ft_strlcpy (temp, c, len + 1);
		val_err = f_texture(var, temp, texture_str);
		free (temp);
		return (val_err);
	}
	return (-1);
}

static int	f_color(t_var *var, char *color_rgb, char *color_str)
{
	if (!ft_strncmp(color_str, "F", 1))
	{
		var->f_color = ft_convert_color(color_rgb);
		if (var->f_color >= 0)
			return (0);
	}
	if (!ft_strncmp(color_str, "C", 1))
	{
		var->c_color = ft_convert_color(color_rgb);
		if (var->c_color >= 0)
			return (0);
	}
	return (-5);
}

static int	filling_color(t_var *var, const char *f_str, char *color_str)
{
	char	*c;
	int		len;
	char	*temp;
	int		val_err;

	val_err = 0;
	c = ft_strnstr (f_str, color_str, ft_strlen(f_str));
	if (c != NULL)
	{
		c += 2;
		while (ft_isspace(*c))
			c++;
		len = 0;
		while (c[len] && !ft_isspace(c[len]))
			len++;
		temp = (char *) malloc (sizeof(char) * (len + 1));
		if (!temp)
			return (-2);
		ft_strlcpy(temp, c, len + 1);
		val_err = f_color(var, temp, color_str);
		free (temp);
		return (val_err);
	}
	return (-1);
}

int	filling(t_var *var, const char *f_str)
{
	if (filling_texture(var, f_str, "NO") < 0
		|| filling_texture(var, f_str, "SO") < 0
		|| filling_texture(var, f_str, "EA") < 0
		|| filling_texture(var, f_str, "WE") < 0)
		return (-4);
	if (filling_color(var, f_str, "F") < 0
		|| filling_color(var, f_str, "C") < 0)
		return (-5);
	return (0);
}
