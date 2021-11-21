#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

# define BUFF_SIZE 1024

int main()
{
	char	buff[BUFF_SIZE];
	int	fd;
	int	i;
	char	temp[100];
	fd = open("./test.txt", O_RDONLY);
	read(fd, buff, BUFF_SIZE);

	temp[1] = buff[1];
	printf("%c\n", temp[1]);
	return (0);
}
