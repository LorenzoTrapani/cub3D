/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:17:18 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/01 16:49:11 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	wall_ends_check(char *line)
{
	while (*line == ' ')
		line++;
	if (*line != '1' || line[ft_strlen(line) - 1] != '1')
		return (0);
	return (1);
}

static bool	wall_line_check(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (false);
	}
	return (true);
}

static bool	start_line_check(char *line, char *prev_line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '0' && prev_line[i] == ' ')
			return (false);
	}
	return (true);
}

static int	middle_line_check(char *line, char *prev_line)
{
	int	len;
	int	prev_len;

	len = ft_strlen(line);
	prev_len = ft_strlen(prev_line);
	if (!start_line_check(line, prev_line))
		return (0);
	if (len > prev_len)
	{
		if (!wall_line_check(line + prev_len))
			return (0);
	}
	else if (len < prev_len)
	{
		if (!wall_line_check(prev_line + len))
			return (0);
	}
	return (1);
}

int	map_validation(t_map map)
{
	int	i;

	i = -1;
	if (map.height == 0 || map.width == 0)
		return (0);
	while (++i < map.height)
	{
		if (!wall_ends_check(map.map_mtx[i]))
			return (printf("%s, %d\n", map.map_mtx[i], i), 0);
		if (i == 0 || i == map.height)
		{
			if (!wall_line_check(map.map_mtx[i]))
				return (printf("%s\n", map.map_mtx[i]), 0);
		}
		else
		{
			if (!middle_line_check(map.map_mtx[i], map.map_mtx[i - 1]))
				return (printf("%s\n", map.map_mtx[i]), 0);
		}
	}
	return (1);
}
