/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strlcat.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausann>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/10/09 12:32:47 by gkoller		   #+#	#+#			 */
/*   Updated: 2023/10/09 12:33:56 by gkoller		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	i;

	if (size <= (size_t) ft_strlen(dst))
		return (size + ft_strlen(src));
	len_dest = ft_strlen(dst);
	i = 0;
	while (src[i] != '\0' && len_dest + 1 < size)
	{
		dst[len_dest] = src[i];
		len_dest++;
		i++;
	}
	dst[len_dest] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}
