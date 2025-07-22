/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_substr.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausann>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/10/09 15:01:17 by gkoller		   #+#	#+#			 */
/*   Updated: 2023/10/09 15:30:14 by gkoller		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */
#include "libft.h"

static char	*sub(char const *s, char *str, unsigned int start, size_t str_len)
{
	size_t	i;

	s += start;
	i = 0;
	while (i < str_len)
	{
		str[i] = s[i];
		i++;
	}
	str[str_len] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	str_len;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len - start < len)
		str_len = s_len - start;
	else
		str_len = len;
	str = (char *)malloc(sizeof(char) * (str_len + 1));
	if (str != NULL)
		str = sub(s, str, start, str_len);
	return (str);
}
