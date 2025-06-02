1, this makefile should start other libs makefiles
2, then this maklefile start its own job

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

#Source file of so long
srcs = $(SRCS_DIR)