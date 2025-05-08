# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/16 12:36:38 by fbanzo-s          #+#    #+#              #
#    Updated: 2025/05/08 18:02:10 by fbanzo-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED     = \033[1;31m
GREEN   = \033[1;32m
YELLOW  = \033[1;33m
RESET   = \033[0m

NAME = so_long
BONUS_NAME = so_long_bonus
HEADER = includes/so_long.h
BONUS_HEADER = includes/so_long_bonus.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
# -fsanitize=address
INCLUDES = -I$(LIBFT_DIR) -Iincludes
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = ./MLX42
MLX = $(MLX_DIR)/build/libmlx42.a
MLX_FLAGS = -ldl -lglfw -pthread -lm
MLX_INC = -I$(MLX_DIR)/include

SRC_DIR = src
OBJ_DIR = obj
BONUS_DIR = bonus

SRCS = so_long.c utils.c parser.c map.c content.c utils_content.c \
mlx_utils.c game.c render.c player.c move.c

BONUS_SRCS = so_long_bonus.c utils_bonus.c parser_bonus.c map_bonus.c content_bonus.c utils_content_bonus.c \
mlx_utils_bonus.c game_bonus.c render_bonus.c player_bonus.c move_bonus.c

SRC = $(addprefix $(SRC_DIR)/, $(SRCS))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

BONUS_SRC = $(addprefix $(BONUS_DIR)/, $(BONUS_SRCS))
BONUS_OBJ = $(addprefix $(OBJ_DIR)/, $(BONUS_SRCS:.c=.o))

all: $(NAME)

bonus: $(BONUS_NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory
	@make -C $(LIBFT_DIR) bonus --no-print-directory

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c $(BONUS_HEADER)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(LIBFT) $(OBJ)
	@echo "$(YELLOW)Compilando $@...$(RESET)"
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(MLX_INC) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)Hecho$(RESET)"

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJ)
	@echo "$(YELLOW)Compilando $@...$(RESET)"
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(MLX) $(MLX_INC) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft -o $(BONUS_NAME)
	@echo "$(GREEN)Hecho$(RESET)"

clean:
	@echo "$(RED)Limpiando objetos...$(RESET)"
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Limpiando todo...$(RESET)"
	@make -C $(LIBFT_DIR) fclean --no-print-directory
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re