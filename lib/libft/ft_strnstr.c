/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strnstr.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausann>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/10/09 12:43:24 by gkoller		   #+#	#+#			 */
/*   Updated: 2023/10/09 12:45:32 by gkoller		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *fisrt, const char *sec, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (*sec == '\0' || sec == NULL)
		return ((char *)fisrt);
	while (fisrt[i] != '\0' && i < len)
	{
		j = 0;
		while (sec[j] == fisrt[i + j] && i + j < len)
		{
			if (sec[j + 1] == '\0')
			{
				return ((char *)fisrt + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
