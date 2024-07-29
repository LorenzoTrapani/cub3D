/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:31:40 by lotrapan          #+#    #+#             */
/*   Updated: 2024/07/29 13:00:17 by lotrapan         ###   ########.fr       */
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
	if (!line)
		return (0);
	if (is_empty(line))
		return (1);
	if (line && line[0] == 'R')
		return (1);
	if (is_texture(line))
		return (1);
	if (line && (line[0] == 'F' || line[0] == 'C'))
		return (1);
	else
		return (1);
}

int	add_map_line(t_data *data, char *line, char **buffer)
{
	const int		len = ft_strlen(line);

	if (line && line[0] != '1')
		return (0);
	*buffer = ft_strjoin(*buffer, line);
	if (len > data->map.width)
		data->map.width = len;
	data->map.height += 1;
	return (1);
}

int	get_map(t_data *data, char *file)
{
	int		fd;
	char	*line;
	char	*buffer;
	int		is_map;

	line = NULL;
	is_map = 0;
	buffer = ft_strdup("");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror("Error: Could not open file\n"), 0);
	line = ft_get_next_line(fd);
	while (line)
	{
		if (line && !check_line(line)) // da freeare line
			return (free(buffer), 0);
		add_map_line(data, line, &buffer);
		free(line);
		line = ft_get_next_line(fd);
	}
	close(fd);
	data->map.map_mtx = ft_split(buffer, '\n');
	free(buffer);
	return (1);
}
