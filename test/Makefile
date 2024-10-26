CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ../srcs/*.c

test: 
	@$(CC) $(CFLAGS) *.c $(SRCS) -o res.out
	@./res.out
	@rm -f res.out

valgrind:
	@$(CC) $(CFLAGS) *.c $(SRCS) -o res.out
	@valgrind ./res.out
	@rm -f res.out