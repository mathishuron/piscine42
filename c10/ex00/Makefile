NAME=ft_display_file
CC=cc
CFLAGS=-Wall -Wextra -Werror
SRC=main.c
OBJ=$(SRC:.c=.o)

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ -c $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: fclean all
