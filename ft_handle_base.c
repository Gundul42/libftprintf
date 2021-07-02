/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:26:29 by graja             #+#    #+#             */
/*   Updated: 2021/07/02 16:34:32 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static
char	*ft_getstr(int nbr, t_flags *flags)
{
	char	*str;

	str = NULL;
	if (flags->type == 'X')
		str = ft_int2base(nbr, 16, "0123456789ABCDEF");
	else if (flags->type == 'x')
		str = ft_int2base(nbr, 16, "0123456789abcdef");
	else if (flags->type == 'u')
		str = ft_int2base(nbr, 10, "0123456789");
	return (str);
}

void	ft_handle_base(t_flags *flags)
{
	char			*str;
	unsigned int	nbr;

	nbr = va_arg(flags->args, unsigned int);
	str = NULL;
	if (flags->point && !flags->max && nbr == 0)
		str = ft_add_spaces(str, flags);
	if (!str)
	{
		str = ft_getstr(nbr, flags);
		if (flags->max)
			str = ft_add_zero_front(str, flags->max);
		if (flags->width && !flags->zero)
			str = ft_add_spaces(str, flags);
		else if (flags->width && flags->zero)
			str = ft_add_zero_front(str, flags->width);
	}
	if (str)
	{
		write(1, str, ft_strlen(str));
		flags->length += ft_strlen(str);
		free(str);
	}
}
