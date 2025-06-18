/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strrchr.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausann>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/10/09 12:36:35 by gkoller		   #+#	#+#			 */
/*   Updated: 2023/10/09 12:37:37 by gkoller		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int sChar)
{
	int	len;

	len = ft_strlen(str);
	str += len;
	while (len >= 0)
	{
		if (*str == (char)sChar)
			return ((char *) str);
		len--;
		str--;
	}
	return (NULL);
}
