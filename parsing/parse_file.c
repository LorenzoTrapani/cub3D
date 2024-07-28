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

int	parse_file(char *file)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
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
