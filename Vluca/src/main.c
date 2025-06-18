/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausanne.ch>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/23 17:53:13 by gkoller		   #+#	#+#			 */
/*   Updated: 2025/05/16 08:35:57 by gkoller		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../header/include.h"

int	main(int argc, char **argv)
{
	t_var	var;

	if (argc != 2)
	{
		printf("Pas assez d'argument!\n");
		return (1);
	}
	if (init(&var, argv[1]) >= 0)
	{
		init_mlx(&var);
	}
	free_var(&var);
	return (0);
}
