NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC =	src/main.c\
		src/check/check_rgb.c		src/check/check_map.c\
		src/init/init.c 			src/init/filling_var.c 	src/init/init_utils.c	src/init/free_var.c\
 		src/init/filling_utils.c 	src/init/init_map.c 	src/init/create_map.c	src/init/init_var.c\
		src/init_mlx/init_mlx.c		src/init_mlx/event.c	src/mlx/init_texture.c\
		src/ray/ray.c				src/ray/ray_utils.c		src/ray/player_mov.c	src/ray/print.c\
		src/ray/textures.c\
		src/collider/collider.c\
		src/minimap/minimap.c

OBJDIR = obj

UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
	MLX_DIR = lib/mlx_mac
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
	MLX_DIR = lib/mlx_linux
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz
endif


OBJ = $(addprefix $(OBJDIR)/, $(notdir $(SRC:.c=.o)))

LIBFT = -Llib/libft

$(NAME): $(OBJ)
	@make -C lib/libft
	@make -C lib/libft bonus
	@make -C lib/mlx_linux
	$(CC) $(OBJ) $(LIBFT) -lft $(MLX_FLAGS) -I$(MLX_DIR) -o $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: src/%.c header/include.h header/define.h | $(OBJDIR)
	$(CC) $(CFLAGS) -I/usr/include -Ilib/libft -Ilib/mlx_linux -c $< -o $@

$(OBJDIR)/%.o: src/check/%.c header/include.h header/define.h | $(OBJDIR)
	$(CC) $(CFLAGS) -I/usr/include -Ilib/libft -Ilib/mlx_linux -c $< -o $@

$(OBJDIR)/%.o: src/init/%.c header/include.h header/define.h | $(OBJDIR)
	$(CC) $(CFLAGS) -I/usr/include -Ilib/libft -Ilib/mlx_linux -c $< -o $@

$(OBJDIR)/%.o: src/mlx/%.c header/include.h header/define.h | $(OBJDIR)
	$(CC) $(CFLAGS) -I/usr/include -Ilib/libft -Ilib/mlx_linux -c $< -o $@

$(OBJDIR)/%.o: src/ray/%.c header/include.h header/define.h | $(OBJDIR)
	$(CC) $(CFLAGS) -I/usr/include -Ilib/libft -Ilib/mlx_linux -c $< -o $@

$(OBJDIR)/%.o: src/collider/%.c header/include.h header/define.h | $(OBJDIR)
	$(CC) $(CFLAGS) -I/usr/include -Ilib/libft -Ilib/mlx_linux -c $< -o $@

$(OBJDIR)/%.o: src/minimap/%.c header/var.h header/include.h header/define.h | $(OBJDIR)
	$(CC) $(CFLAGS) -I/usr/include -Ilib/libft -Ilib/mlx_linux -c $< -o $@
	
all: $(NAME)

clean:
	rm -f $(OBJ)
	rm -rf $(OBJDIR)
	@make -C lib/libft clean
	@make -C lib/mlx_linux clean

fclean: clean
	rm -f $(NAME)
	@make -C lib/libft fclean
	@make -C lib/mlx_linux clean

re: fclean all
