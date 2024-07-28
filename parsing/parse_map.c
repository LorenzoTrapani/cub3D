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

bool	is_texture(char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		return (true);
	if (line[0] == 'S' && line[1] == 'O')
		return (true);
	if (line[0] == 'W' && line[1] == 'E')
		return (true);
	if (line[0] == 'E' && line[1] == 'A')
		return (true);
	if (line[0] == 'S' && line[1] == ' ')
		return (true);
	return (false);
}

bool	is_empty(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (!ft_isspace(line[i]))
			return (false);
		i++;
	}
	return (true);
}

int	check_line(char *line)
{
	if(!line)
		return (0);
	if (is_empty(line))
		return (1);
	/*if (line[0] == 'R')
		return (parse_res(line));
	if (is_texture(line))
		return (parse_texture(line));
	if (line[0] == 'F' || line[0] == 'C')
		return (parse_color(line));
	if (line[0] == '1' || line[0] == ' ')
		return (parse_map(line));*/
	return (1);
}

int	parse_map(char *file)
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
