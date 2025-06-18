/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_lstclear.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausanne.ch>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/07/26 09:15:08 by gkoller		   #+#	#+#			 */
/*   Updated: 2024/07/26 09:15:08 by gkoller		  ###   ########.ch	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*head_list;
	char	*w;

	list = NULL;
	head_list = NULL;
	while (lst != NULL)
	{
		w = f(lst->content);
		list = ft_lstnew(w);
		if (list == NULL)
		{
			free (list);
			free(w);
			ft_lstclear(&head_list, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back (&head_list, list);
	}
	return (head_list);
}
