CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ../srcs/get_next_line.c ../srcs/get_next_line.h ../srcs/get_next_line_utils.c

test: 
	@$(CC) $(CFLAGS) main.c $(SRCS) 
	@./a.out
	@rm -f a.out

valgrind:
	@$(CC) $(CFLAGS) main.c $(SRCS)
	@valgrind --leak-check=full --show-leak-kinds=all ./a.out
	@rm -f a.out