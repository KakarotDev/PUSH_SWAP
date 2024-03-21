CC= cc
CFLAGS= -g -Wall -Wextra -Werror
SRC= push_swap.c stacks.c free_functions.c movements_a.c movements_b.c \
movements_a_and_b.c organizing_the_inverse_pyramid.c \
organizing_the_pyramid.c aux_functions.c under_six.c
OFILES= $(SRC:.c=.o)
NAME= push_swap
LIBFT_DIR= ./libraries/Libft
LIBFT= $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -L$(LIBFT_DIR) -lft -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OFILES)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re bonus