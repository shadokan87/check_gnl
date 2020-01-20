
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY);
	char *line;
	int file;

	(void)argc;
	int count = 0;
	while ((file = get_next_line(fd, &line) > 0))
	{
		printf("| %d |  -->%s\n", file, line);
			count++;
		free(line);
	}
	printf("| %d | -->  %s\n", file, line);
	free(line);
	printf("Total lines : %d", count);
}
