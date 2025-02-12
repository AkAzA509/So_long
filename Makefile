# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 11:51:29 by ggirault          #+#    #+#              #
#    Updated: 2025/02/12 14:23:07 by ggirault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = so_long
NAME_BN = so_long_bonus

CFLAGS = -Wall -Werror -Wextra -g -Wno-unused-result #-fsanitize=address

MLX_DIR = mlx
MLX = $(MLX_DIR)/libmlx.a

SRC = sources/main.c \
	sources/move/move.c \
	sources/window/rendering.c \
	sources/window/itoa.c \
	sources/window/window_manager.c \
	sources/parsing/configuration_checker.c \
	sources/parsing/parse_map.c \
	sources/parsing/parse_map_utils.c \
	sources/parsing/Get_next_line/get_next_line_utils.c \
	sources/parsing/Get_next_line/get_next_line.c

SRCBN = main_bonus.c \
	move/move.c \
	parsing/parse_map.c \
	parsing/configuration_checker.c \
	parsing/parse_map_utils.c \
	parsing/Get_next_line/get_next_line.c \
	parsing/Get_next_line/get_next_line_utils.c \
	window/itoa.c \
	window/rendering.c \
	window/portal_animation.c


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

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ) $(MLX_LIB)
	$(CC) $(CFLAGS) -o $@ $^ -Lmlx -lmlx -lXext -lX11 -lm
	@clear
	@echo "$(CYAN)     ___/\/\/\/\/\_     ____________     ______________     _/\/\___     ____________     ____________     ____________"
	@echo "    _/\/\_________     ___/\/\/\___     ______________     _/\/\___     ___/\/\/\___     _/\/\/\/\___     ___/\/\/\/\_ "
	@echo "   ___/\/\/\/\___     _/\/\__/\/\_     ______________     _/\/\___     _/\/\__/\/\_     _/\/\__/\/\_     _/\/\__/\/\_  "
	@echo "  _________/\/\_     _/\/\__/\/\_     ______________     _/\/\___     _/\/\__/\/\_     _/\/\__/\/\_     ___/\/\/\/\_   "
	@echo " _/\/\/\/\/\___     ___/\/\/\___     ______________     _/\/\/\_     ___/\/\/\___     _/\/\__/\/\_     _______/\/\_    "
	@echo "______________     ____________     _/\/\/\/\/\/\_     ________     ____________     ____________     _/\/\/\/\___     $(RESET)"

minilib:
	@git clone https://github.com/42Paris/minilibx-linux.git
	@mv minilibx-linux mlx
	@cd mlx && ./configure

$(OBJBN_DIR):
	mkdir -p $(OBJBN_DIR)

$(OBJBN_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME_BN): $(OBJBN) $(MLX_LIB)
	$(CC) $(CFLAGS) -o $@ $^ -Lmlx -lmlx -lXext -lX11 -lm

bonus: $(NAME_BN)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(OBJBN_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BN)

re: fclean all

.PHONY: all clean fclean re bonus minilib