#include "cub3D.h"

int main(int argc, char **argv)
{
	if (argc != 2)
		perror("Error: Wrong number of arguments\n");
	if (!parse_file(argv[1]))
		return (0);
	return (1);
}
