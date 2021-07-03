/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 12:14:26 by graja             #+#    #+#             */
/*   Updated: 2021/07/03 11:56:24 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_check_flags(t_flags *flags)
{
	if (flags->percent != 0)
		return (0);
	if (flags->zero && flags->minus)
		flags->zero = 0;
	if (flags->point && flags->zero)
		flags->zero = 0;
	return (1);
}
