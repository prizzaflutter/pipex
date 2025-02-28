NAME= pipex

CC= cc

CFLAGS= -Wall -Wextra -Werror

PRINTF_DIR = ./printf_fd/

PRINTF_LIB= $(PRINTF_DIR)/libftprintf.a

M_SRC= ./Mandatory/main.c ./lib/ft_putstr_fd.c ./lib/ft_bzero.c ./lib/ft_calloc.c ./lib/ft_split.c  ./lib/ft_strncmp.c \
		./lib/ft_strjoin.c ./lib/ft_strlen.c \
		./Mandatory/helpers/check_files.c ./Mandatory/helpers/get_cmd_path.c \
		./Mandatory/children/first_child.c ./Mandatory/children/second_child.c \

M_OBJ= $(M_SRC:.c=.o)


all:  $(PRINTF_LIB) $(NAME)

$(NAME): $(M_OBJ) ./Mandatory/pipex.h
	$(CC) $(CFLAGS) $(M_OBJ) $(PRINTF_LIB) -o $(NAME)

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

clean:
	rm -f $(M_OBJ)
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make fclean -C $(PRINTF_DIR)

re: fclean all