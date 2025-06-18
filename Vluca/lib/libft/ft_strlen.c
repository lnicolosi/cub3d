/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strlen.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausann>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/10/09 12:00:11 by gkoller		   #+#	#+#			 */
/*   Updated: 2023/10/09 12:03:19 by gkoller		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */
#include "libft.h"

int	ft_strlen(const char *str)
{
	int	lenght;

	lenght = 0;
	while (*str)
	{
		lenght++;
		str++;
	}
	return (lenght);
}
