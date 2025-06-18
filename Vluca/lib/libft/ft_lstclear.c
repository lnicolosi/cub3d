/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_lstdelone.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausanne.ch>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/07/26 09:14:41 by gkoller		   #+#	#+#			 */
/*   Updated: 2024/07/26 09:14:41 by gkoller		  ###   ########.ch	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp_list;

	if (lst != NULL)
	{
		while (*lst != NULL)
		{
			temp_list = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = temp_list;
		}
	}
}
