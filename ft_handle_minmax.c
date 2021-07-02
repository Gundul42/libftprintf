/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_minmax.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:23:56 by graja             #+#    #+#             */
/*   Updated: 2021/07/02 13:27:54 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/* check if width or precision has to be read by variable value and puts
 * it in right flag. Call function with 1 for precision, 0 for width
*/

static
void	ft_checkprecision(int nbr, t_flags *flags)
{
	if (nbr >= 0)
	{
		flags->precise = 0;
		flags->max = nbr;
	}
	else
	{
		flags->max = 0;
		flags->precise = 0;
		flags->point = 0;
	}
}

static
void	ft_checkwidth(int nbr, t_flags *flags)
{
	flags->star = 0;
	if (nbr >= 0)
		flags->width = nbr;
	else
	{
		flags->minus = 1;
		flags->zero = 0;
		flags->width = -nbr;
	}
}

void	ft_handle_minmax(t_flags *flags, int chs)
{
	int	nbr;

	nbr = va_arg(flags->args, int);
	if (chs)
		ft_checkprecision(nbr, flags);
	else
		ft_checkwidth(nbr, flags);
}
