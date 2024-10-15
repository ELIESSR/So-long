NAME = so_long

# COLORS
RED     =   \033[91;1m
GREEN   =   \033[92;1m
CLEAR   =   \033[0m

CC = gcc
# FLAGS
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address -fPIC -fPIE

# Librerías necesarias en Linux
MLX_FLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm

RM = rm -f

LIBFT_DIR = libft/

SRCS = src/check.c src/so_long.c src/sprites.c src/utils.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I includes -I minilibx-linux

all: $(NAME)

$(NAME): $(OBJS)
	@make CFLAGS="$(CFLAGS)" -sC $(LIBFT_DIR)
	@make -sC minilibx-linux/
	@cp ./libft/libft.a .
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) libft.a minilibx-linux/libmlx.a $(MLX_FLAGS) -o $(NAME)

clean:
	@$(RM) $(OBJS)
	@make clean -sC $(LIBFT_DIR)
	@make clean -sC minilibx-linux

fclean: clean
	@make fclean -sC $(LIBFT_DIR)
	@$(RM) $(NAME) libft.a

re: fclean all

.PHONY: all clean fclean re
