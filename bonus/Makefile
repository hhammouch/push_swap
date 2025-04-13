NAME= ../checker
CFLAGS= -Wall -Werror -Wextra -g
LIBFT_DIR   = ../libft
LIBFT_LIB   = $(LIBFT_DIR)/libft.a
SRC= checker.c  checker_utils.c ../errors.c ../stack_check.c ../stack_utils.c gnl/get_next_line_utils.c \
	gnl/get_next_line.c operation.c rrr.c \


LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(SRC) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)


clean:
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean

