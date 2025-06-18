NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC =	src/main.c\
		src/init/init.c 			src/init/filling_var.c 	src/init/init_utils.c	src/init/free_var.c\
 		src/init/filling_utils.c 	src/init/init_map.c 	src/init/create_map.c	src/init/check_map.c\
		src/init_mlx/init_mlx.c		src/init_mlx/event.c\
		src/ray/ray.c				src/ray/ray_utils.c		src/ray/player_mov.c	src/ray/print.c

OBJDIR = obj

OBJ = $(addprefix $(OBJDIR)/, $(notdir $(SRC:.c=.o)))

LIBFT = -Llib/libft
MINILIBX = -Llib/mlx_linux -lmlx -L/usr/lib -Ilib/mlx_linux -lXext -lX11 -lm -lz

$(NAME): $(OBJ)
	@make -C lib/libft
	@make -C lib/libft bonus
	$(CC) $(OBJ) $(LIBFT) -lft $(MINILIBX) -o $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -I/usr/include -Ilib/libft -Ilib/mlx_linux -c $< -o $@

$(OBJDIR)/%.o: src/init/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -I/usr/include -Ilib/libft -Ilib/mlx_linux -c $< -o $@

$(OBJDIR)/%.o: src/mlx/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -I/usr/include -Ilib/libft -Ilib/mlx_linux -c $< -o $@

$(OBJDIR)/%.o: src/ray/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -I/usr/include -Ilib/libft -Ilib/mlx_linux -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)
	rm -rf $(OBJDIR)
	@make -C lib/libft clean

fclean: clean
	rm -f $(NAME)
	@make -C lib/libft fclean

re: fclean all