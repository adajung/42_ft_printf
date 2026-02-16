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

NAME		= libft.a

CC		= cc
RM		= rm -f
CFLAGS		= -Wall -Wextra -Werror

%.o:	%.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

SRCS		=	ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c ft_split.c \
			ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
			ft_itoa.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strlcpy.c \
			ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c ft_memcpy.c \
			ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlen.c ft_strrchr.c \
			ft_toupper.c ft_calloc.c ft_isdigit.c ft_memchr.c ft_memset.c \
			ft_putstr_fd.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c
OBJS		= $(SRCS:.c=.o)

SRCS_BONUS	=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
			ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
			ft_lstmap.c ft_lstnew.c ft_lstsize.c
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

ifeq ($(MODE), bonus)
	OBJS := $(OBJS) $(OBJS_BONUS)
endif

all:		$(NAME)
bonus:		
		$(MAKE) all MODE=bonus

$(NAME):	$(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all bonus clean fclean re
