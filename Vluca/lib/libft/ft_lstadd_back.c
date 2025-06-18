/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_lstadd_back.c								   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausann>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/10/14 13:05:33 by gkoller		   #+#	#+#			 */
/*   Updated: 2023/10/14 13:35:36 by gkoller		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp_list;

	temp_list = *lst;
	if (lst != NULL)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			temp_list = ft_lstlast(*lst);
			temp_list->next = new;
		}
	}
}
