/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:09:22 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/01 14:37:08 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_texture(t_tex *texture, char *line, int *error)
{
	char	*path;

	path = ft_strtrim(line + 2, " ,'\n'");
	*error = 0;
	// if (access(path, R_OK) == -1)
	// 	return (perror("Error: Invalid texture\n"), *error = 1);
	if (line[0] == 'N' && line[1] == 'O')
		texture->north = ft_strdup(path);
	if (line[0] == 'S' && line[1] == 'O')
		texture->south = ft_strdup(path);
	if (line[0] == 'W' && line[1] == 'E')
		texture->west = ft_strdup(path);
	if (line[0] == 'E' && line[1] == 'A')
		texture->east = ft_strdup(path);
	free(path);
	return (1);
}
