/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strdup.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausann>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/10/09 12:49:12 by gkoller		   #+#	#+#			 */
/*   Updated: 2023/10/19 10:52:14 by gkoller		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *source)
{
	char	*str;
	int		i;
	int		len;

	len = 0;
	while (source[len] != '\0')
		len++;
	str = (char *)malloc(sizeof (char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = source[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
