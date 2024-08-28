NAME    = push_swap
CC      = cc
CFLAGS  = -Wall -Werror -Wextra -fsanitize=address -g3

SRCS    = push_swap.c parsing1.c parsing2.c utils/ft_atoi_ps.c \
			utils/list_stuff.c

OBJ     = $(SRCS:.c=.o)

PRINTF  = ft_printf_copy/libftprintf.a
LIBFT   = libft_copy/libft.a

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME)

$(LIBFT):
	make -C libft_copy
	
$(PRINTF):
	make -C ft_printf_copy

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIBFT) $(PRINTF)

clean: 
	rm -f $(OBJ)
	make -C libft_copy clean
	make -C ft_printf_copy clean

fclean: clean
	make -C libft_copy fclean
	make -C ft_printf_copy fclean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re