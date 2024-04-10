NAME = so_long

# COLORS
RED		=	\033[91;1m
GREEN	=	\033[92;1m
CLEAR	=	\033[0m

CC = gcc
 # FLAGS
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

RM = rm -f

LIBFT_DIR = libft/

SRCS = src/check.c src/so_long.c src/sprites.c

OBJS = $(SRCS:.c=.o)
	
INCLUDES = -I includes/libft.h -I includes/so_long.h -I MLX/mlx.h

all: $(NAME)

$(NAME): $(OBJS)
	@make -sC $(LIBFT_DIR)
	@make -sC MLX/
	@cp ./libft/libft.a .
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) libft.a MLX/libmlx.a $(MLX_FLAGS)  -o $(NAME)

clean :
		@$(RM) $(OBJS)
		@make clean -sC  $(LIBFT_DIR)
		@make clean -sC  mlx

fclean :	clean
		@make fclean -sC  $(LIBFT_DIR)
		@$(RM) $(NAME) libft.a
		
re : fclean all

.PHONY: all clean fclean re