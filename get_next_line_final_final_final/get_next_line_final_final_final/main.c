#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main()
{
	int	fd;
//	char buff[BUFFER_SIZE];
//	int i = 0;
//	char	*temp;
	fd = open("./test.txt", O_RDONLY);
//	printf("%zd\n", read(fd, buff, BUFFER_SIZE));
//	temp = get_next_line(fd);

//	while(temp != NULL)
//	{
//		printf("%s", temp);
//		temp = get_next_line(fd);
//		i++;
//	}
	printf("one line : %s", get_next_line(fd));
	printf("--------------------------------------\n");
	printf("one line : %s", get_next_line(fd));
	printf("--------------------------------------\n");
	printf("one line : %s", get_next_line(fd));
	printf("--------------------------------------\n");
	// get_next_line(fd);
	// printf("--------------------------------------\n");
	// get_next_line(fd);
	// printf("--------------------------------------\n");
	// get_next_line(fd);
	// printf("--------------------------------------\n");
	// get_next_line(fd);
	// printf("--------------------------------------\n");
	// get_next_line(fd);
	// printf("--------------------------------------\n");
}
