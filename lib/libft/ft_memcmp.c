/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_memcmp.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausann>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/10/09 12:41:55 by gkoller		   #+#	#+#			 */
/*   Updated: 2023/10/09 12:43:13 by gkoller		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t size)
{
	int				diff;
	int				i;
	unsigned char	*pointeur1;
	unsigned char	*pointeur2;

	pointeur1 = (unsigned char *)ptr1;
	pointeur2 = (unsigned char *)ptr2;
	i = 0;
	diff = 0;
	while ((size_t) i < size)
	{
		diff = pointeur1[i] - pointeur2[i];
		i++;
		if (diff)
			return (diff);
	}
	return (diff);
}
