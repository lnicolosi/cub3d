/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   utils.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausanne.ch>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/04 14:15:57 by gkoller		   #+#	#+#			 */
/*   Updated: 2024/12/04 14:15:57 by gkoller		  ###   ########.ch	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char ch)
{
	if ((ch <= 13 && ch >= 9) || ch == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	is_neg;
	int	nb;

	is_neg = 0;
	nb = 0;
	while (*str != '\0' && ft_isspace(*str))
	{
		str++;
	}
	if ((*str == '-' || *str == '+') && *str != '\0')
	{
		if (*str == '-')
			is_neg = 1;
		str++;
	}
	while (*str != '\0' && !ft_isspace(*str) && *str >= '0' && *str <= '9')
	{
		nb *= 10;
		nb += (int) *str - 48;
		str++;
	}
	if (is_neg)
		nb *= -1;
	return (nb);
}
