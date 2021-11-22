#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int	fd;
	int i;
	char	buff[BUFFER_SIZE];
	char	temp[10000];
	fd = open("./test.txt", O_RDONLY);

	printf("THIS IS YOUR ANSWER : %s", get_next_line(fd));
  printf("THIS IS YOUR ANSWER : %s", get_next_line(fd));
  printf("THIS IS YOUR ANSWER : %s", get_next_line(fd));
}
