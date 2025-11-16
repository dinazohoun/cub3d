NAME = cub3d

CC = cc 
CFLAGS = -Wall -Werror -Wextra -g3
INCLUDES = -I./includes -I./libft -I./minilibx-linux 
MLXFLAGS = -L./minilibx-linux -lmlx -lXext -lX11 -lm

OBJ_DIR = objs

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

SRCS = srcs/main.c srcs/setup_graphic.c srcs/utils/utils_args_verif.c \
	srcs/render/render_image.c \
	srcs/load_textures.c \
	

OBJS = $(SRCS:srcs/%.c=$(OBJ_DIR)/%.o) 

GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

all: $(MLX) $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)
	@echo "$(GREEN) compilation SUCCESSFULL$(RESET)"

$(OBJ_DIR)/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compilation $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	
$(LIBFT):
	@echo "$(BLUE)Compilation libft...$(RESET)"
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN) libft compiled!$(RESET)"

$(MLX):
	@echo "$(BLUE)Compilation MiniLibX...$(RESET)"
	@make -C $(MLX_DIR)
	@echo "$(GREEN) MiniLibX compiled!$(RESET)"	

clean: 
	@echo "$(RED) Nettoyage obj files ...! $(RESET)"
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean 
	@make -C $(MLX_DIR) clean 
	@echo "$(GREEN) NETTOYAGE REUSSIE!$(RESET)"

fclean: clean
	@echo "$(RED) Nettoyage TOTAL obj ...! $(RESET)"
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean 
	@echo "$(GREEN) TOTAL NETTOYAGE REUSSIE!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
