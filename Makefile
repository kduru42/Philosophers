NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread
RM = rm -rf

SRCS = time.c philo.c thread.c mutex.c \
status.c dinner.c utils.c check_args.c free.c

MAIN = main.o

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(MAIN) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MAIN) -o $(NAME)

clean:
	$(RM) $(OBJ) $(MAIN)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re