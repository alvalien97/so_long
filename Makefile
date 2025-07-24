SRCS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c draw_map.c load_images.c main.c move_player.c move_utils.c read_map.c validate_map.c validate_coins.c
OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I./libft -I./get_next_line -I./minilibx

NAME = so_long

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MINILIBX_DIR = ./minilibx
MINILIBX_FLAGS = -L$(MINILIBX_DIR) -lmlx -lX11 -lXext -lm
MINILIBX_LIB = $(MINILIBX_DIR)/libmlx.a

all: $(LIBFT) $(MINILIBX_LIB) $(NAME)

$(MINILIBX_LIB):
	@make -C $(MINILIBX_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(MINILIBX_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
