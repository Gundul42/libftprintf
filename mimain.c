/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mimain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 09:54:17 by graja             #+#    #+#             */
/*   Updated: 2021/07/03 13:17:19 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int	main(void)
{
	printf("%5%<<<\n");
	ft_printf("%5%<<<\n");
	printf("%-5%<<<\n");
	ft_printf("%-5%<<<\n");
	printf("%05%<<<\n");
	ft_printf("%05%<<<\n");
	printf("%-05%<<<\n");
	ft_printf("%-05%<<<\n");
	printf("%-5c<<<\n", '\0');
	ft_printf("%-5c<<<\n", '\0');
	printf("%-70.193x%-140c%168c%026.51%%0125.119X\n" ,1102840003u,-50,-17,3721437512u);
	ft_printf("%-70.193x%-140c%168c%026.51%%0125.119X\n" ,1102840003u,-50,-17,3721437512u);
	printf("%--150.*d%01.172i%--151.122d%--*.110x%--23.182% <<<\n" ,193,-1523409169,453642614,881460015,68,2920216226u);
	ft_printf("%--150.*d%01.172i%--151.122d%--*.110x%--23.182% <<<\n" ,193,-1523409169,453642614,881460015,68,2920216226u);
	printf("%043.165%%--35.34s%--4.*d%-189.*i<<<\n" ,"TSvqw0m:$c!hhK(,R*",-100,967600936,45,1272776825);
	ft_printf("%043.165%%--35.34s%--4.*d%-189.*i<<<\n" ,"TSvqw0m:$c!hhK(,R*",-100,967600936,45,1272776825);
	printf("-->|%-16.p|<-- \n", NULL);
	ft_printf("-->|%-16.p|<-- \n", NULL);
	printf("%-5c<<<\n", '\0');
	ft_printf("%-5c<<<\n", '\0');
	printf("{%*c}\n", -15, '\0');
	ft_printf("{%*c}\n", -15, '\0');
	printf("%5c<<<\n", '\0');
	ft_printf("%5c<<<\n", '\0');
	printf(" -%*c* -%-*c* \n", -2, 0, 2, 0);
	ft_printf(" -%*c* -%-*c* \n", -2, 0, 2, 0); 
	printf(" -%-*c* -%-*c* \n", 2, 0, -2, 0);
	ft_printf(" -%-*c* -%-*c* \n", 2, 0, -2, 0); 
	return (0);
}
