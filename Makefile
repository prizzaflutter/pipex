NAME= pipex

NAME_BONUS= pipex_bonus

CC= cc

CFLAGS= -Wall -Wextra -Werror


M_SRC= ./Mandatory/main.c ./lib/lib_ft/ft_putstr_fd.c ./lib/lib_ft/ft_split.c  ./lib/lib_ft/ft_strncmp.c \
		./lib/lib_ft/ft_strjoin.c ./lib/lib_ft/ft_calloc.c ./lib/lib_ft/ft_putchar_fd.c \
		./lib/ft_printf/ft_printf.c  \
		./Mandatory/helpers/check_files.c ./Mandatory/helpers/get_cmd_path.c \
		./Mandatory/children/first_child.c ./Mandatory/children/second_child.c \

B_SRC=	./Bonus/main_bonus.c ./lib/lib_ft/ft_putstr_fd.c ./lib/lib_ft/ft_split.c  ./lib/lib_ft/ft_strncmp.c \
		./lib/lib_ft/ft_strjoin.c ./lib/lib_ft/ft_calloc.c ./lib/lib_ft/ft_putchar_fd.c \
		./lib/ft_printf/ft_printf.c  \
		./lib/get_next_line/get_next_line.c ./lib/get_next_line/get_next_line_utils.c \
		./Bonus/helpers_bonus/check_files.c ./Bonus/helpers_bonus/get_cmd_path.c \
		./Bonus/children_bonus/first_child.c ./Bonus/children_bonus/second_child.c \

M_OBJ= $(M_SRC:.c=.o)

B_OBJ= $(B_SRC:.c=.o)

all: $(NAME)

$(NAME): $(M_OBJ) ./Mandatory/pipex.h
	$(CC) $(CFLAGS) $(M_OBJ) -o $(NAME)


bonus: $(B_OBJ)  ./Bonus/pipex_bonus.h
	$(CC) $(CFLAGS) $(B_OBJ) -o $(NAME_BONUS)

clean:
	rm -f $(M_OBJ) $(B_OBJ)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all