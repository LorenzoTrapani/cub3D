/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:28:11 by lotrapan          #+#    #+#             */
/*   Updated: 2024/09/25 17:13:59 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void get_direction(char c, t_player *player)
{
	if (c == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
	else if (c == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	else if (c == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
	else if (c == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
}

int get_position(char **map_mtx, t_player *player)
{
	int i;
	int j;

	i = -1;
	while (map_mtx[++i])
	{
		j = -1;
		while (map_mtx[i][++j])
		{
			if (map_mtx[i][j] == 'N' || map_mtx[i][j] == 'S' || map_mtx[i][j] == 'E' || map_mtx[i][j] == 'W')
			{
				map_mtx[i][j] = '0';
				player->x = j * TILE_SIZE;
				player->y = i * TILE_SIZE;
				get_direction(map_mtx[i][j], player);
				return (1);
			}
		}
	}
	return (0);
}


void init_player(t_data *data)
{
	if (!get_position(data->map.map_mtx, &data->player)) 
	{
        printf("Error: Player position not found!\n");
        exit(1);
    }
}
