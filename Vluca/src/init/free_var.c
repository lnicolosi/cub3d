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
	var->player.x = 0;
	var->player.y = 0;
	var->player.a = 0;
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
	if (var->map2d)
		free_int_tab(&(var->map2d), var->size_map.y);
}

//a suprimer
void print_map(t_var *var)
{
	int x = 0;
	int y = 0;

	printf("\n");
	while (y < var->size_map.y)
	{
		x = 0;
		while(x < var->size_map.x)
		{
			printf("%d", var->map2d[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
}

void	print_var(t_var *var)
{
	printf("NO = %s\n", var->t_no);
	printf("SO = %s\n", var->t_so);
	printf("EA = %s\n", var->t_ea);
	printf("WE = %s\n", var->t_we);

	printf("F_COLOR: R = %d, G = %d, B = %d\n", ((var->f_color & 0x00FF0000) >> 16), ((var->f_color & 0x0000FF00) >> 8), ((var->f_color & 0x0000FF)));
	printf("C_COLOR: R = %d, G = %d, B = %d\n", ((var->c_color & 0x00FF0000) >> 16), ((var->c_color & 0x0000FF00) >> 8), ((var->c_color & 0x0000FF)));

	print_map(var);
	printf("Player X = %d, Y = %d, A = %f\n", var->player.x, var->player.y, var->player.a);
}
