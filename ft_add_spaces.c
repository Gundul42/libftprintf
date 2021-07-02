/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:25:41 by graja             #+#    #+#             */
/*   Updated: 2021/07/02 12:12:33 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/* fill up with spaces if necessary and copy them to the front or the end of
 * the string depending on the minus flag. Should string length be already
 * larger than the set width, do nothing
*/

char	*ft_add_spaces(char *str, t_flags *flags)
{
	int		len;
	char	*new;
	char	*tmp;

	len = 0;
	if (str)
		len = ft_strlen(str);
	if (len && len >= flags->width)
		return (str);
	new = ft_calloc(flags->width - len + 1, sizeof(char));
	if (!new)
	{
		free(str);
		return (new);
	}
	ft_memset(new, 32, flags->width - len);
	if (!str)
		return (new);
	if (flags->minus)
		tmp = ft_strjoin(str, new);
	else
		tmp = ft_strjoin(new, str);
	free(new);
	free(str);
	return (tmp);
}
