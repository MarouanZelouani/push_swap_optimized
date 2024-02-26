NAME = push_swap
CHECKER = checker

HFILE = ./includes/push_swap.h
GNL_HFILE = ./includes/get_next_line.h
LIBFT_HFILE = ./includes/libft.h

LIBFT = libft.a
LIBFTFOLDER = ./lib/libft
SRC = ./src

CFILES = ./lib/get_next_line/get_next_line.c ./src/utils.c  ./src/new_algo.c ./src/utils_2.c ./src/utils_3.c ./src/push_cases_a.c ./src/adding.c ./src/adding_a.c ./lib/get_next_line/get_next_line_utils.c	checkers/execute.c src/error_checks.c src/free_stack.c src/push_cases.c src/push_operation.c  src/reverse_r_operation.c src/rotate_operation.c src/sort.c src/sort_for_three.c src/stack_utils_2.c src/stack_utils.c src/swap_operation.c

CHECKER_C =		checkers/check_pro.c

PUSH_SWAP_C =	src/push_swap.c

OFILES = $(CFILES:.c=.o)
PUSH_SWAP_O = $(PUSH_SWAP_C:.c=.o)
CHECKER_O = $(CHECKER_C:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g
CC = cc
RM = rm -f
AR = ar rc

GREEN	=	\033[92;1m
BLUE	=	\033[94;1m
CLEAR	=	\033[0m

all: $(NAME) $(CHECKER)
	@echo "$(GREEN)Project Was Built With Success!$(CLEAR)"

makelibft :
		@make -C $(LIBFTFOLDER)
		@cp $(LIBFTFOLDER)/$(LIBFT) .

$(NAME) : makelibft $(OFILES) $(PUSH_SWAP_O)
		@$(CC) $(CFLAGS) $(OFILES) $(PUSH_SWAP_O) $(LIBFT) -o $(NAME)
		

$(CHECKER) : makelibft $(OFILES) $(CHECKER_O)
		@$(CC) $(CFLAGS) $(OFILES) $(CHECKER_O) $(LIBFT) -o $(CHECKER)
		

bonus : $(CHECKER)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

clean : 
	@$(RM) $(OFILES) $(PUSH_SWAP_O) $(CHECKER_O)
	@cd $(LIBFTFOLDER) && make clean
	@$(RM) $(LIBFT)
	@echo "$(BLUE)Done Cleaning..$(CLEAR)"

	 
fclean : clean
	@$(RM) $(NAME) $(CHECKER) $(LIBFT)
	@cd $(LIBFTFOLDER) && make fclean
	@echo "$(BLUE)All is Clean..$(CLEAR)"

.PHONY : clean fclean re all
