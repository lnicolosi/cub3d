/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_striteri.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausann>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/10/14 10:15:40 by gkoller		   #+#	#+#			 */
/*   Updated: 2023/10/14 10:25:37 by gkoller		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	index;

	index = 0;
	while (s[index] != '\0')
	{
		f (index, &s[index]);
		index++;
	}
}
