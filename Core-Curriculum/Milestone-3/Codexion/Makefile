NAME = codexion
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
SRC = coders/main.c coders/init.c coders/coder.c coders/dongle.c \
	coders/monitor.c coders/scheduler.c coders/time.c coders/utils.c \
	coders/heap.c coders/sync_utils.c coders/dongle_pair.c coders/log.c
OBJ = $(SRC:.c=.o)
HEADER = coders/codexion.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(HEADER)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
