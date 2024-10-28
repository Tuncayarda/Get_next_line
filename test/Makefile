CC = cc
CFLAGS = -Wall -Wextra -Werror
SHELL = /bin/zsh
NAME = test.out

SRCS = main.c ../srcs/get_next_line.c ../srcs/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all: test

test: $(OBJS)
	@$(CC) -o $(NAME) $(OBJS)
	@./test.out
	@rm -rf test.out *.o ../srcs/*.o

fsanitize: $(OBJS)
	@$(CC) -g -fsanitize=address -o $(NAME) $(OBJS)
	@./test.out
	@rm -rf test.out *.o ../srcs/*.o

valgrind: $(OBJS)
	@$(CC) -o $(NAME) $(OBJS)
	@valgrind --leak-check=full --show-leak-kinds=all ./test.out
	@rm -rf test.out *.o  ../srcs/*.o

fr:
	@echo BASE_TEST
	@cd ../srcs/ && /Users/tuaydin/francinette/tester.sh
	@/Users/tuaydin/Cleaner_42/Cleaner_42.sh

fr_s:
	@echo STRICT_TEST
	@cd ../srcs/ && /Users/tuaydin/francinette/tester.sh  --strict
	@/Users/tuaydin/Cleaner_42/Cleaner_42.sh

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@