GREEN	= \033[0;32m
YELLOW	= \033[0;33m
RED	= \033[0;31m
BLUE	= \033[0;34m
PURPLE	= \033[0;35m
RESET	= \033[0m

NAME		= push_swap
SRCS_DIR	= srcs
INCS_DIR	= includes
LIBFT_DIR	= libft
OBJS_DIR	= objs

SRCS		= big_sort.c \
		main.c \
		print_stacks.c \
		rotate.c \
		sort_insertion.c \
		swap.c \
		create_sorted_array.c \
		parse_arguments.c \
		push.c \
		small_sort.c \
		stack_op_1.c \
		utils.c \
		find_position.c \
		parse_single_arg.c \
		reverse_rotate.c \
		sort_chunks.c \
		stack_op_2.c

OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
DEPS		= $(OBJS:.o=.d)

LIBFT		= $(LIBFT_DIR)/libft.a

CC		= cc
CFLAGS		= -Wall -Wextra -Werror -MMD -MP
INCLUDES	= -I$(INCS_DIR) -I$(LIBFT_DIR)

all: $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(LIBFT):
	@echo "$(BLUE)Compiling libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)Libft compiled successfully!$(RESET)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	@echo "$(PURPLE)Linking object files...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled successfully!$(RESET)"

clean:
	@echo "$(RED)Removing object files...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJS_DIR)
	@echo "$(GREEN)Object files removed.$(RESET)"

fclean: clean
	@echo "$(RED)Removing executed programs...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "$(GREEN)$(NAME) removed.$(RESET)"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
