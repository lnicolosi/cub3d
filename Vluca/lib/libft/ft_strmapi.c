/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strmapi.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausann>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/10/14 09:33:10 by gkoller		   #+#	#+#			 */
/*   Updated: 2023/10/14 11:00:10 by gkoller		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	index;

	index = 0;
	str = (char *) ft_calloc (ft_strlen(s) + 1, sizeof (char));
	if (str != NULL)
	{
		while (s[index] != '\0')
		{
			str[index] = f(index, s[index]);
			index++;
		}
	}
	return (str);
}
