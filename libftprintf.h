/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:21:54 by graja             #+#    #+#             */
/*   Updated: 2021/07/02 12:55:55 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_flags
{
	va_list	args;
	int		i;
	int		minus;
	int		zero;
	int		star;
	int		width;
	int		percent;
	int		point;
	int		precise;
	int		max;
	char	type;
	int		length;
	int		sign;
}	t_flags;

int			ft_check_flags(t_flags *flags);
t_flags		*ft_clear_flags(t_flags *flags);
t_flags		*ft_decode(const char *str, t_flags *ret);
int			ft_printf(const char *str, ...);
const char	*ft_handle_percent(const char *ptr, t_flags *flags);
void		ft_handle_flags(t_flags *flags);
void		ft_handle_int(t_flags *flags);
void		ft_handle_char(t_flags *flags);
void		ft_handle_minmax(t_flags *flags, int chs);
void		ft_handle_string(t_flags *flags);
void		ft_handle_base(t_flags *flags);
void		ft_handle_pointer(t_flags *flags);
char		*ft_add_zero_front(char *str, int max);
char		*ft_add_spaces(char *str, t_flags *flags);
char		*ft_add_sign(char *str, t_flags *flags);
char		*ft_int2base(unsigned int nbr, unsigned int mbr, char *base);

#endif
