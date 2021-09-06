NAME = libftprintf.a
SOURCES = ft_printf.c
OBJECTS = ${SOURCES:.c=.o}
CFLAGS = -Wall -Werror -Wextra
CC = gcc

${NAME}: ${OBJECTS}
	ar rc ${NAME} ${OBJECTS}

all: ${OBJECTS}
	ar rc ${NAME} ${OBJECTS}

bonus: all

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY = all clean fclean re