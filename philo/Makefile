NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread -g -fsanitize=thread
RM = rm -rf

SRCS = ./src/create_threads.c ./src/init_data.c ./src/philo_utils.c ./src/routine.c  ./src/eat_sleep_think.c ./src/init_forks.c ./src/get_time.c 

MAIN = ./src/main.o

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