#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	char *line = 0;

	while (1)
	{
    	get_next_line(open("cuento_nl.txt", O_RDONLY), &line);
    	//free(line);
	}
	system("leaks a.out");
	return (0);
}
