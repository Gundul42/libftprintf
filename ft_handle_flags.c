/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:59:13 by graja             #+#    #+#             */
/*   Updated: 2021/07/02 11:53:22 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_handle_flags(t_flags *flags)
{
	if (flags->max > 0)
		flags->zero = 0;
	if (flags->type == 'd' || flags->type == 'i')
		ft_handle_int(flags);
	if (flags->type == 'c')
		ft_handle_char(flags);
	if (flags->type == 's')
		ft_handle_string(flags);
	if (flags->type == 'x' || flags->type == 'X' || flags->type == 'u')
		ft_handle_base(flags);
	if (flags->type == 'p')
		ft_handle_pointer(flags);
}
