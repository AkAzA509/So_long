# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggirault <ggirault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 11:51:29 by ggirault          #+#    #+#              #
#    Updated: 2025/01/28 13:45:13 by ggirault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = so_long

CFLAGS = -Wall -Wextra -g -L./minilibx-linux -lmlx_Linux -lm -lX11 -lXext -lbsd #-fsanitize=address

OBJ_DIR = obj/

OBJBN_DIR = objbn/

SRC = $(shell find . -name "*.c")

SRCBN =

OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)

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

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re