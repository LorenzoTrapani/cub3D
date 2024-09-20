/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:28:11 by lotrapan          #+#    #+#             */
/*   Updated: 2024/09/20 17:33:58 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
				player->x = j;
				player->y = i;
				get_angle(map_mtx[i][j], player);
				return (1);
			}
		}
	}
	return (0);
}

void get_angle(char c, t_player *player)
{
	if (c == 'N')
		player->angle = 3 * M_PI_2;
	else if (c == 'S')
		player->angle = M_PI_2;
	else if (c == 'E')
		player->angle = 0;
	else if (c == 'W')
		player->angle = M_PI;
}

void init_player(t_data *data)
{
	get_position(data->map.map_mtx, &data->player);
	printf("Player position: x: %f, y: %f, angle: %f\n", data->player.x, data->player.y, data->player.angle);
}