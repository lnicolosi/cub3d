/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strjoin.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausann>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/10/09 15:34:24 by gkoller		   #+#	#+#			 */
/*   Updated: 2023/10/09 16:05:18 by gkoller		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;

	len = ft_strlen(s1) +ft_strlen(s2);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (str != NULL)
	{
		while (*s1 != '\0')
		{
			*str = *s1;
			str++;
			s1++;
		}
		while (*s2 != '\0')
		{
			*str = *s2;
			str++;
			s2++;
		}
		*str = '\0';
		str -= len;
	}
	return (str);
}
