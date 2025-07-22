/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_memcpy.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausann>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/10/14 10:44:35 by gkoller		   #+#	#+#			 */
/*   Updated: 2023/10/19 10:39:10 by gkoller		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	size_t					i;
	unsigned char			*dst;
	const unsigned char		*src;

	dst = (unsigned char *) destination;
	src = (const unsigned char *) source;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
