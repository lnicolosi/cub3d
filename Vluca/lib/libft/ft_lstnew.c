/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_lstsize.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausanne.ch>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/07/26 09:13:53 by gkoller		   #+#	#+#			 */
/*   Updated: 2024/07/26 09:13:53 by gkoller		  ###   ########.ch	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *) malloc (sizeof (t_list));
	if (list != NULL)
	{
		list->content = content;
		list->next = NULL;
	}
	return (list);
}
