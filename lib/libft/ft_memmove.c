/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_memmove.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausann>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/10/09 12:21:33 by gkoller		   #+#	#+#			 */
/*   Updated: 2023/10/19 10:40:01 by gkoller		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*destination;
	const unsigned char	*source;

	destination = (unsigned char *)dest;
	source = (const unsigned char *)src;
	if (!destination && !source)
		return (NULL);
	if (destination < source || destination >= source + n)
	{
		while (n--)
		{
			*destination++ = *source++;
		}
	}
	else
	{
		destination += n - 1;
		source += n - 1;
		while (n--)
		{
			*destination-- = *source--;
		}
	}
	return (dest);
}
