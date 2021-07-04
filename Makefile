# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 09:37:55 by ctaleb            #+#    #+#              #
#    Updated: 2021/07/04 14:20:04 by ctaleb           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

MAP = assets/maps/showcase.ber

CC = gcc
CFLAGS = -Wall -Wextra #-Werror
RM = rm -rf

INCS_PATH = inc/
LIB_PATH = libft/

SRC_DIR = ./src/

MLX = -L minilibx -lmlx -framework OpenGL -framework AppKit
MLX_PATH = minilibx/

INCS = so_long.h

SRC = so_long.c \
		data_init.c \
		draw_utils.c \
		error_handler.c \
		events.c \
		frame_gen.c \
		map_init.c \
		map.c \
		movement.c \
		movement_utils.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJS = $(SRCS:.c=.o)

LIB = libft.a
MLIB = libmlx.a
NAME = so_long

.PHONY: all bonus clean fclean re run

%.o: %.c $(INCS_PATH)$(INCS)
	$(CC) $(CFLAGS) -I $(INCS_PATH). -o $@ -c $<

all: $(NAME)

$(NAME): $(MLX_PATH)$(MLIB) $(OBJS) $(LIB_PATH)$(LIB)
	$(CC) $(CFLAGS) -o $@ -I $(INCS_PATH). $(OBJS) $(LIB_PATH)$(LIB) $(MLX)

bonus: all

$(LIB_PATH)$(LIB):
	make -C $(LIB_PATH)

$(MLX_PATH)$(MLIB):
	make -C $(MLX_PATH)

run: all
	./$(NAME) $(MAP)

clean:
	$(RM) $(OBJS) $(OBNS)
	make -C $(LIB_PATH) clean
	make -C $(MLX_PATH) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIB_PATH) fclean

re: fclean all