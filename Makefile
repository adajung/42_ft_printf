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
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

CC		= cc
RM		= rm -f
CFLAGS		= -Wall -Wextra -Werror -I$(LIBFT_DIR) -I.
AR		=	ar rcs

SRCS		=	ft_printf.c \
				print_type_c.c \
				print_type_d.c \
				print_type_i.c \
				print_type_p.c \
				print_type_s.c \
				print_type_u.c \
				print_type_x.c \
				print_type_X.c

OBJS		= $(SRCS:.c=.o)

all:		$(NAME)	

$(NAME):	$(OBJS)
		$(MAKE) bonus -C $(LIBFT_DIR)
		cp $(LIBFT) $(NAME)
		$(AR) $(NAME) $(OBJS)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)
		$(MAKE) -C $(LIBFT_DIR) clean

fclean:		clean
		$(RM) $(NAME)
		$(MAKE) -C $(LIBFT_DIR) fclean

re:		fclean all

debug:
	$(MAKE) fclean
	$(MAKE) -C $(LIBFT_DIR) CFLAGS="-Wall -Wextra -Werror -g -I."
	$(MAKE) all CFLAGS="-Wall -Wextra -Werror -g -I. -I$(LIBFT_DIR)"

.PHONY:		all clean fclean re debug
