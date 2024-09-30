CC = cc

CFLAGS = -Wall -Wextra -Werror

all: server client

$(NAME): server client

%.o: %.c
	$(CC) $(CFLAGS)
	
clean :

fclean: clean
	rm -f server client

re: fclean all

.PHONY: all clean fclean re