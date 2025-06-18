/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_memset.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausann>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/10/09 12:03:38 by gkoller		   #+#	#+#			 */
/*   Updated: 2023/10/09 12:09:23 by gkoller		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *) pointer;
	i = 0;
	while (i < count)
	{
		ptr[i] = (unsigned char)value;
		i++;
	}
	return (pointer);
}
