# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehande <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/22 14:24:05 by ehande            #+#    #+#              #
#    Updated: 2020/12/24 15:24:17 by ehande           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a
NAME = libftprintf.a
MAKEF = ./libft/Makefile
SRCS =  \
		ft_printf.c\
		get_flags.c\
		set_int.c\
		set_char.c\
		set_str.c\
		set_uint.c\
		dop.c\
		set_x.c\
		set_p.c\
		
OBJS = ${SRCS:.c=.o}
CC   = gcc
RM   = rm -f
CFLAGS = -Wall -Wextra -Werror
.c.o: = ${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}
$(NAME): ${OBJS}
	make -C libft
	ar rcs ${NAME} ${OBJS} libft/*.o

all: ${NAME}

clean:
	${RM} ${OBJS}
	make clean -C "libft"
fclean: clean
	${RM} ${NAME}
	make fclean -C "libft"
re: fclean all

.PHONY: all clean fclean re
