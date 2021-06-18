# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 09:37:55 by ctaleb            #+#    #+#              #
#    Updated: 2021/06/07 10:01:05 by ctaleb           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

AR = ar
ARFLAGS = rcs

INCS_PATH = inc/
LIB_PATH = libft/

SRC_DIR = ./src/

MLX = -L minilibx -lmlx -framework OpenGL -framework AppKit
MLX_PATH = minilibx/

INCS = so_long.h

SRC = so_long.c \
			utils.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJS = $(SRCS:.c=.o)

LIB = libft.a
MLIB = libmlx.a
NAME = so_long

all: $(NAME)

$(NAME): 