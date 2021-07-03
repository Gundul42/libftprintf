/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:38:47 by graja             #+#    #+#             */
/*   Updated: 2021/07/03 10:28:31 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

const char	*ft_handle_percent(const char *ptr, t_flags *flags)
{
	char	*str;

	str = ft_strjoin("%","");
	if (flags->zero > 0 && !flags->minus)
		str = ft_add_zero_front(str, flags->width);
	if (flags->max)
		str = ft_add_zero_front(str, flags->max);
	if (flags->width)
		str = ft_add_spaces(str, flags);
	write(1, str, ft_strlen(str));
	ptr += flags->i;
	flags->length += ft_strlen(str);
	free(str);
	return (ptr);
}
