
#include "cub3D.h"

int	check_ext(char *file, char *ext)
{
	int	i;
	int	j;

	i = ft_strlen(file);
	j = ft_strlen(ext);
	if (i < j)
		return (0);
	while (j >= 0)
	{
		if (file[i] != ext[j])
			return (0);
		i--;
		j--;
	}
	return (1);
}

int	file_validation(int argc, char **argv)
{
	if (argc != 2)
		return (perror("Error: Wrong number of arguments\n"), 0);
	if (!check_ext(argv[1], ".cub"))
		return (perror("Error: Wrong file extension\n"), 0);
	if (!parse_map(argv[1]))
		return (0);
	return (1);
}