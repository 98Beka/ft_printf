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
		
		


CC = gcc
FLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)

$(NAME):  $(OBJS)
	make $(MAKEF)
	cp $(LIBFT) $(NAME)
	$(CC) -c $(FLAGS) $(SRCS)
	ar -rcs $(NAME)  $(OBJS) 
	
all : $(NAME)

a:
	$(CC) -g  $(SRCS) $(LIBFT) -o a

q:
	$(CC) -g $(SRCS) $(FLAGS) main2.c $(LIBFT) -o q



clean :
	rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME) libftprintf.a
	rm -rf $(NAME)

re : fclean all


.PHONY: clean fclean all ref *.o a q