NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

SRC_DIR = src
LIBFT_DIR = libft
BONUS_DIR = bonus

SRC= push_swap.c errors.c stack_check.c stack_utils.c three_five.c \
	sort/rotate.c sort/swap.c sort/reverse_rotate.c sort/push.c sort_stacks.c

LIBFT = $(LIBFT_DIR)/libft.a

BONUS = $(BONUS_DIR)/checker

all: $(LIBFT) $(NAME)

bonus: $(LIBFT) $(BONUS)

$(BONUS):
	@$(MAKE) -C $(BONUS_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(SRC) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(BONUS_DIR) fclean

re: fclean all

.PHONY: clean
