# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 13:21:37 by graja             #+#    #+#              #
#    Updated: 2021/07/03 13:59:13 by graja            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFT		= libft
LIBFT_LIB	= libft.a
SRCS = ft_printf.c ft_decode.c ft_handle_flags.c ft_handle_int.c \
       ft_handle_char.c ft_handle_percent.c ft_check_flags.c ft_clear_flags.c \
       ft_handle_minmax.c ft_add_zero_front.c ft_add_spaces.c ft_add_sign.c \
       ft_handle_string.c ft_int2base.c ft_handle_base.c ft_handle_pointer.c

OBJS		= $(SRCS:.c=.o)
INCS		= .
RM			= rm -f
LIBC		= ar rc
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

re : fclean all

bonus : fclean
	echo '>>> NO BONUS AVAILABLE <<<'
