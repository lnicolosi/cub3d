/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_bzero.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausann>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/10/09 12:09:35 by gkoller		   #+#	#+#			 */
/*   Updated: 2023/10/14 10:33:38 by gkoller		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *pointer, size_t count)
{
	size_t				i;
	unsigned char		*ptr;

	ptr = (unsigned char *) pointer;
	i = 0;
	while (i < count)
	{
		ptr[i] = 0;
		i++;
	}
}
