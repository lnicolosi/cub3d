/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strtok.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausanne.ch>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/07/14 10:35:30 by gkoller		   #+#	#+#			 */
/*   Updated: 2024/07/14 10:35:30 by gkoller		  ###   ########.ch	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	int	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && size > 1)
		{
			dest[i] = src[i];
			size--;
			i++;
		}
		dest[i] = '\0';
	}
	return ((size_t) ft_strlen(src));
}
