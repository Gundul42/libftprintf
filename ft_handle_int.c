/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:09:49 by graja             #+#    #+#             */
/*   Updated: 2021/07/02 13:36:52 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static
char	*ft_cutsign(char *str)
{
	if (*str != '-')
		return (str);
	str = ft_memmove(str, str + 1, ft_strlen(str));
	return (str);
}

static
int	ft_siglen(t_flags *flags)
{
	if (flags->sign == 0)
		return (0);
	else
		return (1);
}

static
void	ft_printit(char *str, t_flags *flags)
{
	if (str)
	{
		write(1, str, ft_strlen(str));
		flags->length += ft_strlen(str);
		free(str);
	}
}

void	ft_handle_int(t_flags *flags)
{
	char	*str;
	int		nbr;

	str = NULL;
	nbr = va_arg(flags->args, int);
	if (flags->point && !flags->max && nbr == 0)
		str = ft_add_spaces(str, flags);
	if (!str)
	{
		if (nbr < 0)
			flags->sign = -1;
		str = ft_itoa(nbr);
		str = ft_cutsign(str);
		if (flags->zero > 0)
			str = ft_add_zero_front(str, flags->width - ft_siglen(flags));
		if (flags->max)
			str = ft_add_zero_front(str, flags->max);
		str = ft_add_sign(str, flags);
		if (flags->width)
			str = ft_add_spaces(str, flags);
	}
	ft_printit(str, flags);
}
