NAME       = cub3D
CC         = cc
CFLAGS     = -Wall -Wextra -Werror -g -I./include
RM         = rm -f
LIBFT      = libft/libft.a

SRC		   = main.c \


all: $(NAME)

$(NAME): $(SRC)
	@[ -f $(LIBFT) ] || make -C libft/
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "${BLUE} ${NAME} -> ${YELLOW}Success${NO_COLOR}"
	@${MAKE} camel

clean:
	@$(RM) -r 
	@make clean -C libft/

fclean: clean
	@make fclean -C libft/
	@$(RM) $(NAME)

re: fclean all

.SILENT: re
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