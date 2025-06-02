1, this makefile should start other libs makefiles
2, then this maklefile start its own job

#git repo
#git@github.com:talaykajungle/42_so_long.git#

NAME : so_long

#Compiler
CC = cc

#Compiler Flags
CFLAGS = -Wall -Werror -Wextra

#path to so_long
SRCS_DIR = ./srcs

# paths to the other Makefiles
LIBFT_DIR = ./srcs/libs/libft
PRINTF_DIR = ./srcs/libs/ft_printf
GNL_DIR = ./src/libs/42_get_next_line
MLX_DIR = ./srcs/libs/mlx

#libft files
LIBFT_DIR = $(LIBFT_A)/libft.a
PRINTF_DIR = $(PRINTF_DIR)/libftprintf.a
MLX_DIR = $(MLX_DIR)/libmlx.a

#Source file of so long
srcs = so_long.c

objs = $(SRCS_DIR: .c = .o)


