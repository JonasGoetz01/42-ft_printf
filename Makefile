NAME	= libftprintf.a

SOURCES	= ft_printf.c \
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

LIBFT_DIR	= ./libft

LIBFT		= $(LIBFT_DIR)/libft.a

.c.o:
	cc ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCLUDES}

${NAME}: ${OBJECTS} $(LIBFT)
	ar rc ${NAME} ${OBJECTS}
	ranlib ${NAME}

$(LIBFT):
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)

all: ${NAME}

clean:
	rm -f ${OBJECTS}
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f ${NAME}

re: fclean all
