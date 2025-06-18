/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_calloc.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausann>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/10/09 12:50:22 by gkoller		   #+#	#+#			 */
/*   Updated: 2023/10/14 10:34:12 by gkoller		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nb_case, size_t case_size)
{
	void	*tab;

	tab = malloc (nb_case * case_size);
	if (tab != NULL)
	{
		ft_memset(tab, 0, nb_case * case_size);
		return (tab);
	}
	return (NULL);
}
