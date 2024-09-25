NAME       = cub3D
CC         = cc
CFLAGS 		= -Wall -Wextra -Werror -g -Iinclude -Ilibft -Imlx
LDFLAGS		= -Llibft -Lmlx
LINKS		= -lft -lm -lmlx -lX11 -lXext
RM         = rm -f
LIBFT      = libft/libft.a
MINILIBX   = mlx/libmlx.a

SRC		   = src/main.c \
			src/init/file_validation.c \
			src/init/parse_line.c \
			src/init/texture.c \
			src/init/map_validation.c \
			src/free/cleanup.c \
			src/mlx/game_loop.c \
			src/mlx/draw.c \
			src/mlx/render.c \
			src/mlx/window.c \
			src/mlx/rays.c \
			src/mlx/minimap.c \
			src/player/movement.c \
			src/player/player.c \
			src/player/rotation.c \

all: $(NAME)

$(NAME): $(SRC)
	@[ -f $(LIBFT) ] || make -C libft/
	@[ -f $(MINILIBX) ] || make -C mlx/ > /dev/null 2>&1
	@$(CC) $(CFLAGS) $(LDFLAGS) $(SRC) $(LINKS) -o $(NAME)
	@echo "${BLUE} ${NAME} -> ${YELLOW}Success${NO_COLOR}"

clean:
	@make clean -C libft/
	@make clean -C ./mlx/ > /dev/null 2>&1
	@echo "${BLUE} ${NAME} -> ${RED}Cleaned${NO_COLOR}"

fclean: clean
	@make fclean -C libft/
	@make clean -C ./mlx/ > /dev/null 2>&1
	@$(RM) $(NAME)
	@echo "${BLUE} ${NAME} -> ${RED}Fcleaned${NO_COLOR}"

re: fclean all

valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.SILENT:
.PHONY: all clean fclean re

RED         := ${shell tput setaf 1}
BLUE        := ${shell tput setaf 4}
YELLOW      := ${shell tput setaf 3}
NO_COLOR    := ${shell tput sgr0}
BOLD        := ${shell tput bold}
