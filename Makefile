NAME       = cub3D
CC         = cc
CFLAGS     = -Wall -Wextra -Werror -g -I./include
LDFLAGS    = -Lmlx -lmlx -Llibft -lft -L/usr/include/../lib -lXext -lX11 -lm
RM         = rm -f
LIBFT      = libft/libft.a
MINILIBX   = mlx/libmlx.a
SRC_DIR    = src
OBJ_DIR    = obj

SRCS       = main.c \

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@[ -f $(LIBFT) ] || make -C libft/
	@[ -f $(MINILIBX) ] || make -C ./mlx/
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "${BLUE} ${NAME} -> ${YELLOW}Success${NO_COLOR}"
	@${MAKE} camel

clean:
	@$(RM) -r $(OBJS)
	@make clean -C libft/

fclean: clean
	@make clean -C ./mlx/
	@make fclean -C libft/
	@$(RM) $(NAME)

re: fclean all

.SILENT: all
.PHONY: all clean fclean re

RED         := ${shell tput setaf 1}
BLUE        := ${shell tput setaf 4}
YELLOW      := ${shell tput setaf 3}
NO_COLOR    := ${shell tput sgr0}
BOLD        := ${shell tput bold}

camel:
	
	@echo '	    ⣎⣓⢶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ '
	@echo '	⢰⡩⢪⡁⢉⣿⠄⢿⣶⠆⠀⠀⠀⡠⠒⠢⠀⠀⠀⠀⠀⠀⠀⠀⠀'
	@echo '	⣾⣀⣎⡱⢢⡉⠴⠀⡾⠀⠀⠀⡸⠒⠀⠀⠱⡄⠀⠀⠀⠀⠀⠀⠀'
	@echo '	⠙⠛⠁⠀⠘⠀⠀⢸⠁⢀⠠⠮⣤⣀⣀⡀⣀⣸⠷⠦⢀⠀⠀⠀⠀'
	@echo '	⠀⠀⠀⠀⠘⡄⠀⠈⠒⡎⠀⠀⠀⠀⠈⠉⠉⠀⠀⠈⢒⠵⠀⠀⠀'
	@echo '	⠀⠀⠀⠀⠀⠈⠢⠄⡀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠘⣗⡀⠀⠀'
	@echo '	⠀⠀⠀⠀⠀⠀⠀⠀⠈⡟⡀⠀⠀⣰⣞⣀⢠⠶⡀⠀⠸⡉⢳⠦⠀'
	@echo '	⠀⠀⠀⠀⠀⠀⠀⠀⠀⢳⢡⠀⠠⠃⠀⠀⠈⠶⡈⠣⡀⢱⠵⣀⠇'
	@echo '	⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⣰⠀⢰⠀⠀⠀⠀⠀⠈⢣⢥⢠⠇⠹⠀'
	@echo '	⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⢩⠏⠇⠀⠀⠀⠀⠀⢀⢆⠞⡜⠀⠀⠀'
	@echo '	⠀⠀⠀⠀⠀⠀⠀⢀⣠⠎⠜⠐⡄⠀⠀⠀⣀⡠⠊⣦⠂⠃⠀⠀⠀'
	@echo '	⠀⠀⠀⠀⠀⠀⠀⠈⠛⠯⢎⣢⡥⠀⠀⠘⠺⠼⢮⡟⣄⠇⠀⠀⠀'