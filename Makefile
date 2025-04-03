NAME= push_swap
CFLAGS= -Wall -Werror -Wextra
LIBFT_DIR   = libft
LIBFT_LIB   = $(LIBFT_DIR)/libft.a
SRC= push_swap.c error.c stack_check.c stack_utils.c



all: $(NAME) $(LIBFT_LIB)

$(NAME): $(LIBFT_LIB) $(SRC)
	cc $(CFLAGS) $(SRC) $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: clean
