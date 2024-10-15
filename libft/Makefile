NAME = libft.a
BONUS_NAME = libftbonus.a
RM = rm -f

CC = cc
AR = ar -crs
RM = rm -f

# COLORS
RED		=	\033[91;1m
GREEN	=	\033[92;1m
CLEAR	=	\033[0m

CFLAGS = -Wall -Wextra -Werror -fPIC -fPIE

SRCs = char/ft_isalnum.c		\
	   char/ft_isalpha.c		\
	   char/ft_isascii.c		\
	   char/ft_isdigit.c		\
	   char/ft_isprint.c		\
	   char/ft_tolower.c		\
	   char/ft_toupper.c		\
	   str/ft_split.c		\
	   str/ft_strlen.c		\
	   str/ft_strlcpy.c		\
	   str/ft_strchr.c		\
	   str/ft_strrchr.c		\
	   str/ft_strlcat.c		\
	   str/ft_strnstr.c		\
	   str/ft_strncmp.c		\
	   str/ft_strdup.c		\
	   str/ft_substr.c		\
	   str/ft_strjoin.c		\
	   str/ft_strtrim.c		\
	   str/ft_strmapi.c		\
	   str/ft_striteri.c	\
	   mem/ft_memset.c		\
	   mem/ft_bzero.c		\
	   mem/ft_memcpy.c		\
	   mem/ft_memmove.c		\
	   mem/ft_memchr.c		\
	   mem/ft_memcmp.c		\
	   mem/ft_calloc.c		\
	   conv/ft_atoi.c		\
	   conv/ft_itoa.c		\
	   put/ft_putchar_fd.c	\
	   put/ft_putstr_fd.c	\
	   put/ft_putnbr_fd.c	\
	   put/ft_putendl_fd.c	\

SRCS_PRINTF = printf/format_printf.c	\
			printf/ft_printf.c	\

SRCS_GNL = get_next_line/get_next_line_utils.c	\
		get_next_line/get_next_line.c	\
			
BONUS = lst/ft_lstnew_bonus.c		\
		lst/ft_lstadd_front_bonus.c	\
		lst/ft_lstsize_bonus.c		\
		lst/ft_lstlast_bonus.c		\
		lst/ft_lstadd_back_bonus.c	\
		lst/ft_lstdelone_bonus.c	\
		lst/ft_lstclear_bonus.c		\
		lst/ft_lstiter_bonus.c		\
		lst/ft_lstmap_bonus.c		\


BONUS_OBJS = $(BONUS:.c=.o)

OBJS = $(SRCs:.c=.o)

OBJS_GNL = $(SRCS_GNL:.c=.o)

OBJS_PRINTF = $(SRCS_PRINTF:.c=.o)

INCLUDE = libft.h

all : $(NAME)

$(NAME) : $(OBJS) $(OBJS_GNL) $(OBJS_PRINTF)
	@echo "$(GREEN)Compiling Libft ...$(CLEAR)"
	@$(AR) $(NAME) $(OBJS) $(OBJS_GNL) $(OBJS_PRINTF)
	@echo "$(GREEN)Done !$(CLEAR)"
 

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(OBJS) $(OBJS_GNL) $(OBJS_PRINTF) $(BONUS_OBJS)
	@$(AR) $(BONUS_NAME) $(OBJS) $(OBJS_GNL) $(OBJS_PRINTF) $(BONUS_OBJS)
	@echo "$(GREEN)Compiling Libft bonus ...$(CLEAR)"
	@$(AR) $(NAME) $(OBJS) $(OBJS_GNL) $(OBJS_PRINTF) $(BONUS_OBJS)
	@echo "$(GREEN)Done !$(CLEAR)"
	
clean:
	$(RM) $(OBJS) $(OBJS_GNL) $(OBJS_PRINTF) $(BONUS_OBJS)
	@echo "$(RED)Remove .o from libft ...$(CLEAR)"

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	@echo "$(RED)Everything Deleted.$(CLEAR)"

re: fclean all

.PHONY: all bonus clean fclean re