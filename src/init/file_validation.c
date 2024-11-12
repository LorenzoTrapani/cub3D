/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:17:28 by lotrapan          #+#    #+#             */
/*   Updated: 2024/11/12 18:29:32 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	add_map_line(t_data *data, char *line, char **buffer)
{
	const int		len = ft_strlen(line);
	int				i;

	i = 0;
	while (line && ft_isspace(line[i]))
		i++;
	if (line && line[i] != '1')
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
	int		valid;

	line = NULL;
	valid = 1;
	buffer = ft_strdup("");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror("Error: Could not open file\n"), 0);
	line = ft_get_next_line(fd);
	while (line)
	{
		if (!parse_line(&data->tex, line))
			valid = 0;
		add_map_line(data, line, &buffer);
		free(line);
		line = ft_get_next_line(fd);
	}
	close(fd);
	if (!valid)
		return (free(buffer), 0);
	data->map.map_mtx = ft_split(buffer, '\n');
	return (free(buffer), 1);
}

int	check_extension(char *file, char *ext)
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

int	file_validation(t_data *data, int argc, char **argv)
{
	int	check;

	check = 0;
	if (argc != 2)
		return (perror("Error: Wrong number of arguments\n"), 0);
	if (!check_extension(argv[1], ".cub"))
		return (perror("Error: Wrong file extension\n"), 0);
	if (!get_map(data, argv[1]))
		return (cleanup(data), perror("Error: Invalid map\n"), 0);
	if (!map_validation(data->map))
		return (cleanup(data), perror("Error: Invalid map\n"), 0);
	check = get_position(data->map.map_mtx, &data->player);
	if (check != 1)
	{
		cleanup(data);
		if (check == 0)
			return (perror("Error: No player position\n"), 0);
		else
			return (perror("Error: Multiple player positions\n"), 0);
	}
	return (1);
}
