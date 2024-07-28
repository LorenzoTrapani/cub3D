/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:31:40 by lotrapan          #+#    #+#             */
/*   Updated: 2024/07/28 17:20:42 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_line(char *line)
{
	if (line)
		printf("Daje\n");
	return (1);
}

int	get_map(char *file)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror("Error: Could not open file\n"), 0);
	line = ft_get_next_line(fd);
	while (line)
	{
		if (!check_line(line))
			return (0);
		free(line);
		line = ft_get_next_line(fd);
	}
	return (1);
}

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

int	check_map(char *file)
{
	//parsing map
	if (!get_map(file))
		return (0);
	return (1);
}

int	map_validation(int argc, char **argv)
{
	if (argc != 2)
		return (perror("Error: Wrong number of arguments\n"), 0);
	if (!check_ext(argv[1], ".cub"))
		return (perror("Error: Wrong file extension\n"), 0);
	if (!check_map(argv[1]))
		return (0);
	return (1);
}
