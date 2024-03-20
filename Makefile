NAME = push_swap


LIBFT = ./libs/Libft/libft.a


CC = gcc -g
CCFLAGS = -Wall -Werror -Wextra 
RM = rm
RMFLAGS= -f 

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

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CCFLAGS) $(OBJ) $(LIBFT) -o $(NAME)


$(LIBFT):
	$(MAKE) -C ./libs/Libft/

clean:
	$(RM) $(RMFLAGS) $(OBJ)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME) $(OBJ)
	$(MAKE) fclean -C ./libs/Libft/

re: fclean all bonus
