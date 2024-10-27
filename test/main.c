#include "../srcs/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

//void leaks_check() __attribute__((destructor));

int main()
{
	int fd;
	char *p;

	fd = open("test_files/files_0/multiple_line_with_nl", O_RDWR);
	printf("fd:%d\n",fd);

	p = get_next_line(fd);
	printf(" 1: %s", p);
	free(p);
	p = get_next_line(fd);
	printf(" 1: %s", p);
	free(p);
	
	p = get_next_line(fd);
	printf(" 1: %s", p);
	free(p);

	p = get_next_line(fd);
	printf(" 1: %s", p);
	free(p);
	p = get_next_line(fd);
	printf(" 1: %s", p);
	free(p);
	
	p = get_next_line(fd);
	printf(" 1: %s", p);
	free(p);
	
	p = get_next_line(fd);
	printf(" 1: %s", p);
	free(p);

}

/* void leaks_check()
{
	system("leaks a.out");
} 
 */