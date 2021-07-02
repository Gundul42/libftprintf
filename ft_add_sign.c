/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:52:48 by graja             #+#    #+#             */
/*   Updated: 2021/07/02 12:35:48 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_add_sign(char *str, t_flags *flags)
{
	char	*new;

	if (flags->sign == 0)
		return (str);
	else if (flags->sign < 0)
		new = ft_strjoin("-", str);
	else if (flags->sign > 1)
		new = ft_strjoin("+", str);
	free(str);
	return (new);
}
