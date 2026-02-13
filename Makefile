# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hwalee <hwalee@student.42gyeongsan.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/08 14:00:48 by hwalee            #+#    #+#              #
#    Updated: 2025/11/14 16:09:53 by hwalee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_printf.a

CC		= cc
RM		= rm -f
CFLAGS		= -Wall -Wextra -Werror -I. -I./libft

LDFLAGS = -L./libft
LDLIBS = -lft
%.o:	%.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

SRCS		=	ft_printf.c print_type_c.c print_type_d.c print_type_i.c\
			print_type_p.c print_type_s.c print_type_u.c print_type_x.c\
			print_type_X.c

OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		make -C ./libft
		ar rcs $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)
		make -C ./libft fclean

re:		fclean $(NAME)

.PHONY:		all clean fclean re