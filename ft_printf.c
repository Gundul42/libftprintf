/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:52:56 by graja             #+#    #+#             */
/*   Updated: 2021/07/02 11:42:23 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static
const char	*ft_printuntil(const char *ptr, t_flags *flags)
{
	while (*ptr && *ptr != '%')
	{	
		write(1, ptr, 1);
		flags->length++;
		ptr++;
	}
	return (ptr);
}

static
int	ft_parse_string(const char *ptr, t_flags *flags)
{
	int		err;

	err = 1;
	while (*ptr)
	{
		flags = ft_clear_flags(flags);
		ptr = ft_printuntil(ptr, flags);
		if (!*ptr)
			return (flags->length);
		ptr++;
		flags = ft_decode(ptr, flags);
		err = ft_check_flags(flags);
		if (err > 0)
		{
			ft_handle_flags(flags);
			ptr += flags->i;
		}
		else if (err == 0)
		{
			ptr = ft_handle_percent(ptr, flags);
			ptr += flags->i;
		}
	}
	return (flags->length);
}

int	ft_printf(const char *str, ...)
{
	t_flags	*flags;
	int		n;

	flags = malloc(sizeof(t_flags));
	if (!str || !flags)
	{
		if (flags)
			free(flags);
		return (-1);
	}
	flags->length = 0;
	va_start(flags->args, str);
	n = ft_parse_string(str, flags);
	va_end(flags->args);
	free(flags);
	return (n);
}
