/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:14:22 by graja             #+#    #+#             */
/*   Updated: 2021/07/02 12:11:39 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_handle_char(t_flags *flags)
{
	char	*str;
	char	c;

	str = ft_calloc(2, sizeof(char));
	if (!str)
		return ;
	c = va_arg(flags->args, int);
	str[0] = c;
	if (flags->width)
		str = ft_add_spaces(str, flags);
	if (!c && ft_strlen(str))
		str[ft_strlen(str) - 1] = c;
	write(1, str, ft_strlen(str));
	if (!c)
	{
		write(1, "\0", 1);
		flags->length++;
	}
	flags->length += ft_strlen(str);
	free(str);
}
