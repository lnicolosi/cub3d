/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoller <gkoller@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:17:24 by gkoller           #+#    #+#             */
/*   Updated: 2025/07/02 15:21:33 by gkoller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/include.h"

static int	check_rgb_while(int *i, char **str_rgb)
{
	int		j;
	char	*clean;

	if (*i >= 3)
		return (-1);
	clean = ft_strtrim(str_rgb[*i], " \t");
	if (!clean || clean[0] == '\0')
	{
		free(clean);
		return (-1);
	}
	j = 0;
	while (clean[j])
	{
		if (clean[j] < '0' || clean[j] > '9')
		{
			free(clean);
			return (-1);
		}
		j++;
	}
	free(str_rgb[*i]);
	str_rgb[*i] = clean;
	(*i)++;
	return (0);
}

int	check_rgb(char **str_rgb)
{
	int	i;

	i = 0;
	while (str_rgb[i])
	{
		if (check_rgb_while(&i, str_rgb) < 0)
			return (-1);
	}
	if (i != 3)
		return (-1);
	return (0);
}
