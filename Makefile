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

LIBFT = libft.a
NAME = libftprintf.a
SRCS =  \
		ft_printf.c \
		putchar_next.c \
		get_flags.c\
		set_int.c\
		set_char.c\
		set_str.c\
		


CC = gcc
FLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	cp $(LIBFT) $(NAME)
	$(CC) -c $(FLAGS) $(SRCS)
	ar -rcs $(NAME)  $(OBJS) 
	
all : $(NAME)


a:
	$(CC) -g $(FLAGS) $(SRCS) $(LIBFT) -o a

q:
	$(CC) -g $(SRCS) main2.c $(LIBFT) -o q



clean :
	rm -rf $(SURPL_O) $(OBJS)

fclean : clean
	@rm -rf $(NAME) libftprintf.a
	rm -rf $(NAME)

re : fclean all


.PHONY: clean fclean all ref *.o a q