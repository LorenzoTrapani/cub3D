/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:28:11 by lotrapan          #+#    #+#             */
/*   Updated: 2024/11/11 19:11:09 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_direction(char c, t_player *player)
{
	if (c == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->dir_angle = 270;
	}
	else if (c == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->dir_angle = 90;
	}
	else if (c == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->dir_angle = 180;
	}
	else if (c == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->dir_angle = 0;
	}
}

static int	is_valid_char(char c)
{
	return (c != '0' && c != '1' && c != ' ' && c != 'N' && c != 'S'
		&& c != 'E' && c != 'W');
}

int	get_position(char **map_mtx, t_player *player)
{
	int	i;
	int	j;
	int	found;

	i = -1;
	found = 0;
	while (map_mtx[++i])
	{
		j = -1;
		while (map_mtx[i][++j])
		{
			if (is_valid_char(map_mtx[i][j]))
				return (0);
			if (map_mtx[i][j] == 'N' || map_mtx[i][j] == 'S' ||
				map_mtx[i][j] == 'E' || map_mtx[i][j] == 'W')
			{
				player->x = j * TILE_SIZE;
				player->y = i * TILE_SIZE;
				get_direction(map_mtx[i][j], player);
				map_mtx[i][j] = '0';
				found++;
			}
		}
	}
	return (found);
}
