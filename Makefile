#1, this makefile should start other libs makefiles
#2, then this maklefile start its own job#

#git repo
#git@github.com:talaykajungle/42_so_long.git#
.SILENT: $(OBJS) $(NAME) $(LIBFT_A)

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCS_DIR = ./srcs
LIBFT_DIR = ./libs/libft
PRINTF_DIR = ./libs/ft_printf
MLX_DIR = ./libs/minilibx-linux

# Library files
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
MLX = $(MLX_DIR)/libmlx.a

# Sources
SRCS = $(SRCS_DIR)/so_long.c
OBJS = $(SRCS:.c=.o)

LIBFT_SRCS = $(wildcard $(LIBFT_DIR)/*.c)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

PRINTF_SRCS = $(wildcard $(PRINTF_DIR)/*.c)
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(LIBFT) $(PRINTF) $(MLX) $(NAME)

$(LIBFT): $(LIBFT_OBJS)
	ar rcs $@ $^

$(PRINTF): $(PRINTF_OBJS)
	ar rcs $@ $^

$(MLX):
	make -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(PRINTF) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(LIBFT_OBJS) $(PRINTF_OBJS)

fclean: clean
	rm -f $(NAME) $(LIBFT) $(PRINTF)

re: fclean all

.PHONY: all clean fclean re