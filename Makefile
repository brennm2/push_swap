NAME = push_swap

LIBFT = ./libs/Libft/libft.a

CC = gcc -g
CCFLAGS = -Wall -Werror -Wextra 
RM = rm
RMFLAGS= -f
GREEN=\033[0;32m
RED=\033[0;31m
YELLOW=\033[1;93m
NC=\033[0m

SRC = main.c \
		src/stack_init.c \
		src/stack_erros.c \
		src/stack_utils.c \
		src/compile_stack_a.c \
		src/compile_stack_b.c \
		src/commands/rotate.c \
		src/commands/reverse_rotate.c \
		src/commands/swap.c \
		src/commands/push.c \
		src/commands/organize_stacks.c \
		src/commands/sort_three.c



OBJ = $(SRC:.c=.o)
LOCATION = obj/

all: $(NAME)


$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CCFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	

	@echo "\n${YELLOW}--------------------------"
	@echo "${YELLOW}| ${GREEN}All files are compiled ${YELLOW}|"
	@echo "${YELLOW}--------------------------${NC}\n"

$(LIBFT):
	$(MAKE) -C ./libs/Libft/

clean:
	$(RM) $(RMFLAGS) obj/* $(OBJ)

	@echo "\n${YELLOW}-----------------------------"
	@echo "${YELLOW}| ${GREEN}Cleaned all ${RED}program${GREEN} files ${YELLOW}|"
	@echo "${YELLOW}-----------------------------${NC}\n"

fclean: clean
	$(RM) $(RMFLAGS) $(NAME) $(OBJ)
	$(MAKE) fclean -C ./libs/Libft/

	@echo "\n${YELLOW}--------------------------------"
	@echo "${YELLOW}| ${RED}ALL files ${GREEN}have been cleaned! ${YELLOW}|"
	@echo "${YELLOW}--------------------------------${NC}\n"

re: fclean all
