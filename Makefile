# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 11:51:29 by ggirault          #+#    #+#              #
#    Updated: 2025/02/03 12:10:33 by ggirault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = so_long

CFLAGS = -Wall -Werror -Wextra -g -Wno-unused-result #-fsanitize=address

MLX_DIR = mlx
MLX = $(MLX_DIR)/libmlx.a

SRC = sources/main.c \
	sources/window/rendering.c \
	sources/window/window_manager.c \
	sources/parsing/configuration_checker.c \
	sources/parsing/parse_map.c \
	sources/parsing/parse_map_utils.c \
	sources/parsing/Get_next_line/get_next_line_utils.c \
	sources/parsing/Get_next_line/get_next_line.c
	
SRCBN =

OBJ_DIR = obj/
OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)

OBJBN_DIR = objbn/
OBJBN = $(SRCBN:%.c=$(OBJBN_DIR)%.o)

GREEN = \033[0;32m
RESET = \033[0m
RED = \033[38;5;1m
WHITE = \033[38;5;7m
CYAN = \033[38;5;6m
YELLOW = \033[38;5;3m
MAGENTA = \033[38;5;5m

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ) $(MLX_LIB)
	$(CC) $(CFLAGS) -o $@ $^ -Lmlx -lmlx -lXext -lX11 -lm

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re