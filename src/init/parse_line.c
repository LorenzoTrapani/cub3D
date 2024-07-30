/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:31:40 by lotrapan          #+#    #+#             */
/*   Updated: 2024/07/30 15:46:25 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	is_texture(char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		return (true);
	if (line[0] == 'S' && line[1] == 'O')
		return (true);
	if (line[0] == 'W' && line[1] == 'E')
		return (true);
	if (line[0] == 'E' && line[1] == 'A')
		return (true);
	return (false);
}

static bool	is_empty(char *line)
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

static int	rgb_to_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	get_color(t_tex *texture, char *line, int *error)
{
	int		r;
	int		g;
	int		b;

	r = ft_atoi(line + 2, error);
	g = ft_atoi(ft_strchr(line + 2, ',') + 1, error);
	b = ft_atoi(ft_strrchr(line + 2, ','), error);
	if (line[0] == 'F')
		texture->floor = rgb_to_int(r, g, b);
	else
		texture->ceiling = rgb_to_int(r, g, b);
}

int	parse_line(t_tex *texture, char *line, int *error)
{
	if (!line)
		return (*error = 1);
	else if (is_empty(line))
		return (1);
	else if (is_texture(line))
		return (get_texture(texture, line, error));
	else if (line && (line[0] == 'F' || line[0] == 'C'))
		return (get_color(texture, line, error), 1);
	return (1);
}
