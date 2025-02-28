SOURCE =  ft_putnbr.c ft_printf.c ft_putchar.c ft_putstr.c ft_printf_hex.c ft_printf_add.c 	ft_printf_uns.c

OBJECTS = ${SOURCE:.c=.o}
NAME = libftprintf.a
LIBC = ar rcs
RM = rm -rf
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJECTS}
	${LIBC} ${NAME} ${OBJECTS}

%.o: %.c ft_printf.h
	${CC} ${CFLAGS} -c $< 
clean:
	${RM} ${OBJECTS} 

fclean: clean
	${RM} ${NAME} 

re: fclean all