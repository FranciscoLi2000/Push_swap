# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yufli <yufli@student.42barcelona.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/18 07:28:28 by yufli             #+#    #+#              #
#    Updated: 2025/05/18 07:33:32 by yufli            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC		= cc
CFLAGS		= -Wall -Wextra -Werror -Iincludes

SRCDIR		= srcs
OBJDIR		= objs

SRCFILES	= \
	assign_indices.c ft_strlcpy.c parse_single_arg.c \
	rotate.c sort_two.c find_largest_pos.c  \
	input_validation.c push.c sort_butterfly.c \
	stack.c ft_split.c main.c quick_sort.c sort_five.c \
	stack_utils.c ft_strchr.c parse_multiple_args.c \
	reverse_rotate.c sort_three.c swap.c

SRC			= $(addprefix $(SRCDIR)/, $(SRCFILES))
OBJ			= $(addprefix $(OBJDIR)/, $(SRCFILES:.c=.o))

GREEN	= \033[0;32m
RESET	= \033[0m

all: $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Compiled $(NAME)$(RESET)"

clean:
	@rm -rf $(OBJDIR)
	@echo "$(GREEN)Cleaned object files"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)Fully cleaned"

re: fclean all

.PHONY: all clean fclean re
