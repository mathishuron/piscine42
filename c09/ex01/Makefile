NAME=libft.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror

MY_SOURCES =srcs/ft_putchar.c \
	    srcs/ft_swap.c \
	    srcs/ft_putstr.c \
	    srcs/ft_strlen.c \
	    srcs/ft_strcmp.c

MY_HEADER=$(MY_HEADER_FOLDER)/ft.h

MY_HEADER_FOLDER=includes

MY_OBJECTS=$(MY_SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	ar rcs $@ $(MY_OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(MY_HEADER_FOLDER)

clean:
	rm -f $(MY_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
