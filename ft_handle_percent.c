/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:38:47 by graja             #+#    #+#             */
/*   Updated: 2021/07/02 12:10:45 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

const char	*ft_handle_percent(const char *ptr, t_flags *flags)
{
	write(1, "%", 1);
	if (flags->type != 'R')
		ptr++;
	else
		ptr += flags->i;
	flags->length++;
	return (ptr);
}
