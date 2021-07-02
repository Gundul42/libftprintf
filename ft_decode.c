/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 13:28:11 by graja             #+#    #+#             */
/*   Updated: 2021/07/02 12:24:05 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static
const char	*ft_readnbr(const char *str, t_flags *flags, int width)
{
	if (width)
	{
		while (*str && *str >= '0' && *str <= '9')
		{
			flags->width = flags->width * 10 + *str - '0';
			str++;
			flags->i++;
		}
	}
	else
	{
		while (*str && *str >= '0' && *str <= '9')
		{
			flags->max = flags->max * 10 + *str - '0';
			str++;
			flags->i++;
		}
	}
	return (str);
}

static
const char	*ft_readflags(const char *str, t_flags *ret)
{
	while (*str && *str != '.' && (!ft_isalnum(*str) || *str == '0'))
	{
		if (*str == '%')
		{
			ret->percent++;
			return (str);
		}
		if (*str == '-')
			ret->minus++;
		if (*str == '*')
			ret->star++;
		if (*str == '0')
			ret->zero++;
		str++;
		ret->i++;
	}
	return (str);
}

static
const char	*ft_readprec(const char *str, t_flags *ret)
{
	if (*str != '.')
		return (str);
	ret->point = 1;
	str++;
	ret->i++;
	if (ft_isdigit(*str))
		return (ft_readnbr(str, ret, 0));
	if (*str == '*')
	{
		ret->precise = 1;
		str++;
		ret->i++;
	}
	return (str);
}

t_flags	*ft_decode(const char *str, t_flags *ret)
{
	str = ft_readflags(str, ret);
	str = ft_readnbr(str, ret, 1);
	str = ft_readprec(str, ret);
	if (ret->star)
		ft_handle_minmax(ret, 0);
	if (ret->precise)
		ft_handle_minmax(ret, 1);
	if (*str && ft_isalpha(*str))
	{
		ret->type = *str;
		ret->i++;
	}
	else if (*str && *str == '%')
		ret->percent++;
	return (ret);
}
