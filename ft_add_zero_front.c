/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_zero_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:20:13 by graja             #+#    #+#             */
/*   Updated: 2021/07/02 11:47:40 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static
char	*ft_fillup(char *str, int maxlen)
{
	char	*new;
	char	*zeros;

	zeros = ft_calloc(maxlen + 1, sizeof(char));
	if (!zeros)
	{
		free(str);
		return (zeros);
	}
	ft_memset(zeros, 48, maxlen);
	new = ft_strjoin(zeros, str);
	free(zeros);
	free(str);
	return (new);
}

char	*ft_add_zero_front(char *str, int max)
{
	int	nlen;

	if (!str)
		return (str);
	nlen = ft_strlen(str);
	if (nlen >= max)
		return (str);
	str = ft_fillup(str, max - nlen);
	return (str);
}
