/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strncmp.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausanne.ch>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/07/30 10:18:50 by gkoller		   #+#	#+#			 */
/*   Updated: 2024/07/30 10:19:19 by gkoller		  ###   ########.ch	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, unsigned int len)
{
	unsigned int	i;

	i = 0;
	if (len == 0)
		return (0);
	while (first[i] == second[i] && first[i] != '\0'
		&& second[i] != '\0' && i < len - 1)
		i++;
	return (first[i] - second[i]);
}
