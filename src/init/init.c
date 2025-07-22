/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   init.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausanne.ch>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/05/16 08:28:33 by gkoller		   #+#	#+#			 */
/*   Updated: 2025/05/16 09:23:43 by gkoller		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../header/include.h"

int	print_msg_err(int val_err, char **f_str)
{
	printf("Error\n");
	if (val_err == -1)
		printf("Fichier inexistant!\n");
	if (val_err == -2)
		printf("Erreur malloc!\n");
	if (val_err == -3)
		printf("Fichier vide!\n");
	if (val_err == -4)
		printf("Probleme texture!\n");
	if (val_err == -5)
		printf("Probleme couleur!\n");
	if (val_err == -6)
		printf("Probleme allocation map!\n");
	if (val_err == -7)
		printf("Probleme format map!\n");
	if (val_err == -8)
		printf("Nombre de joueur incorect!\n");
	if (val_err == -9)
		printf("Extension de fichier invalide! (doit être .cub)\n");
	if (f_str && *f_str)
		free(*f_str);
	return (val_err);
}

static int	content_file(const char *path, char **f_str)
{
	int		fd;
	int		len;
	char	c;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	len = 0;
	while (read(fd, &c, 1) > 0)
		len++;
	close(fd);
	if (len == 0)
		return (-3);
	*f_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!*f_str)
		return (-2);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	len = 0;
	while (read(fd, &c, 1) > 0)
		(*f_str)[len++] = c;
	(*f_str)[len] = '\0';
	close(fd);
	return (0);
}

int	check_path(char *path)
{
	char	*extension;
	int		path_len;

	if (!path)
		return (-9);
	path_len = ft_strlen(path);
	if (path_len < 4)
		return (-9);
	extension = ft_strnstr(path, ".cub", path_len);
	if (!extension)
		return (-9);
	if (ft_strlen(extension) == 4)
		return (0);
	return (-9);
}

int	init(t_var *var, const char *path)
{
	char	*f_str;
	int		val_err;

	init_var(var, &f_str);
	val_err = check_path((char *)path);
	if (val_err < 0)
		return (print_msg_err(val_err, &f_str));
	val_err = content_file(path, &f_str);
	if (val_err < 0)
		return (print_msg_err(val_err, &f_str));
	val_err = filling(var, f_str);
	if (val_err < 0)
	{
		free_textures(var);
		return (print_msg_err(val_err, &f_str));
	}
	val_err = init_map(var, f_str);
	if (val_err < 0)
		return (print_msg_err(val_err, &f_str));
	if (var->player.nb != 1)
		return (print_msg_err(-8, &f_str));
	free(f_str);
	minimap_init(var);
	return (0);
}
