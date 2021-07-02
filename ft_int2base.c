/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int2base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 15:48:41 by graja             #+#    #+#             */
/*   Updated: 2021/07/02 12:09:22 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static
unsigned int	ft_count_len(unsigned int n, unsigned int mbr)
{
	unsigned int	ret;

	ret = 1;
	while (n > mbr - 1)
	{
		ret++;
		n /= mbr;
	}
	return (ret);
}

/* change nbr according to the given new base. mbr is the number of members in
 * the new base and *base is a string containing all equivalent characters from
 * low to high
*/

char	*ft_int2base(unsigned int nbr, unsigned int mbr, char *base)
{
	char			*str;
	unsigned int	i;
	unsigned int	len;

	len = ft_count_len(nbr, mbr);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (str);
	i = 0;
	while (nbr >= mbr)
	{
		str[len - i - 1] = base[nbr % mbr];
		nbr /= mbr;
		i++;
	}
	str[len - i - 1] = base[nbr];
	return (str);
}
