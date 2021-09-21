NAME =		libftprintf.a
SOURCES =	ft_printf.c print_char.c  print_hexadecimal.c  print_int.c \
			print_pointer.c  print_string.c  print_unsigned_int.c \
			ft_printf_utils.c ft_printf_check_flags.c ft_printf_get_formaters.c
OBJECTS =	${SOURCES:.c=.o}
CFLAGS =	-Wall -Werror -Wextra
CC =		gcc

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