/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 12:19:08 by graja             #+#    #+#             */
/*   Updated: 2021/07/02 12:33:12 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flags	*ft_clear_flags(t_flags *flags)
{
	flags->i = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->star = 0;
	flags->percent = 0;
	flags->width = 0;
	flags->point = 0;
	flags->precise = 0;
	flags->max = 0;
	flags->type = 0;
	flags->sign = 0;
	return (flags);
}
