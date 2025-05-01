# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/16 12:36:38 by fbanzo-s          #+#    #+#              #
#    Updated: 2025/05/01 18:26:34 by fbanzo-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED     = \033[1;31m
GREEN   = \033[1;32m
YELLOW  = \033[1;33m
RESET   = \033[0m

NAME = so_long
HEADER = includes/so_long.h
CC = cc
#CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(LIBFT_DIR) -I.
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = ./MLX42
MLX = $(MLX_DIR)/build/libmlx42.a
MLX_FLAGS = -ldl -lglfw -pthread -lm
MLX_INC = -I$(MLX_DIR)/include

SRC_DIR = src
OBJ_DIR = obj

SRCS = so_long.c utils.c parser.c map.c content.c utils_content.c \
mlx_utils.c game.c render.c
SRC = $(addprefix $(SRC_DIR)/, $(SRCS))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory
	@make -C $(LIBFT_DIR) bonus --no-print-directory

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT) $(OBJ) $(OBJ_MAIN)
	@echo "$(YELLOW)Compilando $@...$(RESET)"
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(MLX_INC) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)Hecho$(RESET)"

clean:
	@echo "$(RED)Limpiando objetos...$(RESET)"
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Limpiando todo...$(RESET)"
	@make -C $(LIBFT_DIR) fclean --no-print-directory
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re