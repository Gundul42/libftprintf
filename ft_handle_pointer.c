/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:14:22 by graja             #+#    #+#             */
/*   Updated: 2021/07/03 12:30:30 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static
char	*ft_swapandfree(char *new, char *str)
{
	char	*tmp;

	if (ft_strlen(new) && ft_strlen(str) == 1)
	{
		tmp = ft_strjoin("0", str);
		free(str);
		str = tmp;
	}
	tmp = ft_strjoin(new, str);
	free(str);
	free(new);
	return (tmp);
}

static
char	*ft_makeadr(unsigned char *adr, unsigned int size)
{
	char			*new;
	char			*str;
	unsigned int	i;

	new = ft_calloc(size + 1, sizeof(unsigned char));
	if (!new)
		return (new);
	i = 0;
	while (i < size)
	{
		str = ft_int2base(*adr, 16, "0123456789abcdef");
		new = ft_swapandfree(new, str);
		adr--;
		i++;
	}
	i = 0;
	while (new[i] == '0')
		i++;
	new = ft_memmove(new, new + i, ft_strlen(new) - i + 1);
	str = ft_strjoin("0x", new);
	free(new);
	return (str);
}

static
char	*ft_getptr_adr(void *ptr)
{
	char			*str;
	unsigned char	*adr;
	unsigned int	size;

	size = sizeof(ptr);
	adr = (unsigned char *)&ptr;
	adr += (size - 1);
	str = ft_makeadr(adr, size);
	return (str);
}

/* on apple use 0x0 while on linux use (nil) */

void	ft_handle_pointer(t_flags *flags)
{
	void	*src;
	char	*str;

	src = va_arg(flags->args, void *);
	str = ft_getptr_adr(src);
	if (!str)
		return ;
	if (!ft_strncmp(str, "0x", 3) && !flags->point)
	{
		free(str);
		str = ft_strjoin("0x0", "");
	}
	if (flags->width)
		str = ft_add_spaces(str, flags);
	write(1, str, ft_strlen(str));
	flags->length += ft_strlen(str);
	free(str);
}
