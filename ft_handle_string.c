/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:14:22 by graja             #+#    #+#             */
/*   Updated: 2021/07/02 17:11:21 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static
char	*ft_makestr(char *str, int len, t_flags *flags)
{
	char	*ptr;

	if (!str)
	{
		str = "(null)";
		len = ft_strlen(str);
	}
	if (flags->max && flags->max < len)
		len = flags->max;
	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (ptr);
	if ((!(flags->point && !flags->max)))
		ft_memcpy(ptr, str, len);
	if (flags->width)
		ptr = ft_add_spaces(ptr, flags);
	return (ptr);
}

void	ft_handle_string(t_flags *flags)
{
	char	*str;
	char	*ptr;
	int		len;

	len = 0;
	str = va_arg(flags->args, char *);
	if (str)
		len = ft_strlen(str);
	ptr = NULL;
	if (flags->point && !flags->max && len == 0)
		ptr = ft_add_spaces(ptr, flags);
	if ((!ptr) || !(flags->point && !flags->max && len))
	{
		if (ptr)
			free(ptr);
		ptr = ft_makestr(str, len, flags);
	}
	if (ptr)
	{
		write(1, ptr, ft_strlen(ptr));
		flags->length += ft_strlen(ptr);
		free(ptr);
	}
}
