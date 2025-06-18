/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_itoa.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gkoller <gkoller@student.42lausann>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/10/19 11:59:03 by gkoller		   #+#	#+#			 */
/*   Updated: 2023/10/19 11:59:08 by gkoller		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

static int	size_num(long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	if (n == -2147483648)
		return (10);
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char	*num_str(char *str, long int n)
{
	if (n == 0)
		*str = '0';
	while (n > 0)
	{
		*str = (n % 10) + '0';
		str--;
		n /= 10;
	}
	return (str);
}

static void	ft_isneg(long int *nb, char *str)
{
	*str = '-';
	*nb *= -1;
}

char	*ft_itoa(int nb)
{
	int			is_neg;
	int			snum;
	char		*str_num;
	char		*p;
	long int	long_nb;

	is_neg = 0;
	p = NULL;
	if (nb < 0)
		is_neg = 1;
	long_nb = (long int) nb;
	snum = size_num(long_nb);
	str_num = (char *) ft_calloc(snum + is_neg + 1, sizeof(char));
	if (!str_num)
		return (NULL);
	p = str_num;
	if (is_neg)
		ft_isneg (&long_nb, str_num);
	str_num = num_str(str_num + snum + is_neg - 1, long_nb);
	return (p);
}
