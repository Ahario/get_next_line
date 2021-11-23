#include "get_next_line.h"
#include <fcntl.h>

int main()
{
	int	fd;
	int i = 0;
	char	*temp;
	fd = open("./test.txt", O_RDONLY);
	temp = get_next_line(fd);

	while(temp != NULL)
	{
		printf("%s", temp);
		temp = get_next_line(fd);
		i++;
	}
	printf("%d\n", i);
//	get_next_line(fd);
//	printf("--------------------------------------\n");
//	get_next_line(fd);
//	printf("--------------------------------------\n");
//	get_next_line(fd);
//	printf("--------------------------------------\n");
//	get_next_line(fd);
//	printf("--------------------------------------\n");
//	get_next_line(fd);
//	printf("--------------------------------------\n");
//	get_next_line(fd);
//	printf("--------------------------------------\n");
//	get_next_line(fd);
//	printf("--------------------------------------\n");
//	get_next_line(fd);
//	printf("--------------------------------------\n");
}
