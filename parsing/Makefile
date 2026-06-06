NAME = cub3d
CC = cc
HEADER = cub3d.h
SRC = main.c \
	  raycasting/init_data.c \
	  raycasting/handle_key.c \
	  raycasting/raycasting_algo.c \
	  raycasting/raycasting_algo2.c \
	  raycasting/utils.c \
	  src/floor_ceiling_range_check.c \
	  src/texture_checks.c \
	  src/handle_errors.c \
	  src/init_reset_data.c \
	  src/free_after_parsing.c \
	  src/flood_fill_map.c \
	  src/map_validation.c \
	  src/extract_map.c \
	  src/premap_element_checks.c \
	  src/extract_floor_and_ceiling.c \
	  src/extract_textures.c \
	  src/get_number_of_lines.c \
	  src/file_checking.c \
	  src/get_file_data.c \
	  gnl/get_next_line.c \
	  gnl/get_next_line_utils.c
LIBFT = libft.a
FT_PRINTF = libftprintf.a
FT_PRINTF_DIR = ft_printf
LIBFT_DIR = libft
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
CFLAGS  = -Wall -Wextra -Werror -I$(MLX_DIR)
LDFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
OBJ = $(SRC:.c=.o)

.SECONDARY: $(SRC)

all: $(FT_PRINTF) $(LIBFT) $(MLX_LIB) $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)


$(MLX_LIB):
	@make -C $(MLX_DIR)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) \
		-L$(LIBFT_DIR) -lft \
		-L$(FT_PRINTF_DIR) -lftprintf \
		$(LDFLAGS) \
		-o $(NAME)

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean
	@make -C $(FT_PRINTF_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(FT_PRINTF_DIR) fclean
re: fclean all

.PHONY: clean
