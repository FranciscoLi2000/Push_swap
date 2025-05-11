# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/11 21:08:17 by yufli             #+#    #+#              #
#    Updated: 2025/05/11 21:25:01 by yufli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC		= cc
CFLAGS		= -Wall -Wextra -Werror

SRC_FILES	= ft_atoi.c ft_isalnum.c ft_isdigit.c ft_memchr.c \
		ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlcat.c \
		ft_strmapi.c ft_strrchr.c ft_tolower.c ft_bzero.c \
		ft_isalpha.c ft_isprint.c ft_memcmp.c ft_memset.c \
		ft_split.c ft_striteri.c ft_strlcpy.c ft_strncmp.c \
		ft_strtrim.c ft_toupper.c ft_calloc.c ft_isascii.c \
		ft_itoa.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c \
		ft_strjoin.c ft_strlen.c ft_strnstr.c ft_substr.c

OBJ_FILES	= $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
