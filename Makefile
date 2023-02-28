NAME		=	solve

ARC			=	puzzle.a

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror

OBJS_DIR	=	objects/
OBJS		=	$(addprefix $(OBJS_DIR), $(notdir $(SRC:.c=.o)))

SRC			=	check_args.c		\
				init.c				\
				ft_atoi.c			\
				edge_clues.c		\
				assign_candidate.c	\
				print_cell.c

SRC_DIR		=	src

vpath %.c $(SRC_DIR)

all:			$(NAME)

$(NAME):		main.c $(ARC)
			@echo "Compiling: main.c"
			$(CC) $(FLAGS) -I. main.c $(OBJS) -o $(NAME)

$(ARC):			$(OBJS)
			@ar rc $(ARC) $(OBJS)

$(OBJS_DIR)%.o:	%.c
			@mkdir -p $(OBJS_DIR)
			@echo "Compiling: $<"
			$(CC) $(FLAGS) -I. -c $< -o $@

clean:
			@rm -rf objects

fclean:			clean
			@rm -rf $(NAME) puzzle.a

re:				fclean all
