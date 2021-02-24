#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd;
	int r;
	char *line = 0;
	int i = 0;

	fd = 0;
	fd = open("cuento_nl.txt", O_RDONLY);
	r = 1;
	while (r == 1)
	{
		r = get_next_line(-1,  &line);
		if (line)
			free(line);
		printf("%s\n", line);
		i++;
	}
	printf("\n\nFINAL\n\n");
	close(fd);
	system("leaks a.out");
	return (0);
}
