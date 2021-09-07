NAME =		libftprintf.a
SOURCES =	ft_printf.c ft_print_char.c  ft_print_hexadecimal.c  ft_print_int.c \
			ft_print_pointer.c  ft_print_string.c  ft_print_unsigned_int.c \
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