/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   utils.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausanne.ch>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/05/16 09:49:23 by gkoller		   #+#	#+#			 */
/*   Updated: 2025/05/16 11:50:05 by gkoller		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../../header/include.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (c);
	return (0);
}

void	free_char_tab(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_int_tab(int ***tab, int size_tab)
{
	int	i;

	i = 0;
	while (i < size_tab)
	{
		free ((*tab)[i]);
		i++;
	}
	free (*tab);
}

static void	copy_str(char c1, char *c2, int *index)
{
	if (!ft_isspace(c1))
	{
		*c2 = c1;
		(*index)++;
	}
}

char	*del_space(char *c)
{
	int		i;
	int		len;
	int		len_tot;
	char	*str;

	i = 0;
	len = 0;
	len_tot = 0;
	while (c[++i] && c[i] != '\n')
	{
		if (ft_isspace(c[i]))
			len++;
		len_tot++;
	}
	len_tot = len_tot - len + 1;
	str = (char *) malloc (sizeof(char) * len_tot);
	if (str == NULL)
		return (NULL);
	i = 0;
	len = 0;
	while (c[i++] && c[i] != '\n')
		copy_str(c[i], &str[len], &len);
	str[len_tot - 1] = '\0';
	return (str);
}
