#include "../srcs/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void leaks_check() __attribute__((destructor));

int main()
{
	int fd;
	char *p;

	fd = open("test_files/files_1/only_nl.txt", O_RDWR);
	printf("fd:%d\n",fd);

	p = get_next_line(fd);
	printf(" 1: %s", p);
	free(p);

	p = get_next_line(fd);
	printf(" 2: %s", p);
	free(p);

	p = get_next_line(fd);
	printf(" 3: %s", p);
	free(p);
}

/* void leaks_check()
{
	system("leaks a.out");
} 
 */
