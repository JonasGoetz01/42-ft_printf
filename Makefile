NAME	= libftprintf.a

SOURCES	= ft_printf.c \
	ft_print_char.c \
	ft_print_str.c \
	ft_print_ptr.c \
	ft_print_dec.c \
	ft_print_int.c \
	ft_print_udec.c \
	ft_print_lhex.c \
	ft_print_uhex.c \
	ft_print_percent.c


OBJECTS	= ${SOURCES:.c=.o}

INCLUDES	= libftprintf.h

CFLAGS	= -Wall -Wextra -Werror

.c.o:
	cc ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCLUDES}

${NAME}: ${OBJECTS}
	ar rc ${NAME} ${OBJECTS}
	ranlib ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${NAME}

re: fclean all