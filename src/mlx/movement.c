/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:05:27 by lotrapan          #+#    #+#             */
/*   Updated: 2024/09/24 17:14:49 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_right(t_data *data, double new_x, double new_y)
{
	if (data->map.map_mtx[(int)(data->player.y + (new_x * TILE_SIZE / 2)) / TILE_SIZE]
		[(int)(data->player.x + (new_y * TILE_SIZE / 2)) / TILE_SIZE] == '0')
	{
		data->player.x += new_y;
		data->player.y += new_x;
	}
}

void	move_left(t_data *data, double new_x, double new_y)
{
	if (data->map.map_mtx[(int)(data->player.y - (new_x * TILE_SIZE / 2)) / TILE_SIZE]
		[(int)(data->player.x - (new_y * TILE_SIZE / 2)) / TILE_SIZE] == '0')
	{
		data->player.x -= new_y;
		data->player.y -= new_x;
	}
}

void	move_forward(t_data *data, double new_x, double new_y)
{
	if (data->map.map_mtx[(int)(data->player.y - (new_x * TILE_SIZE / 2)) / TILE_SIZE]
		[(int)(data->player.x - (new_y * TILE_SIZE / 2)) / TILE_SIZE] == '0')
	{
		data->player.x -= new_y;
		data->player.y -= new_x;
	}
}

void	move_backward(t_data *data, double new_x, double new_y)
{
	if (data->map.map_mtx[(int)(data->player.y + (new_x * TILE_SIZE / 2)) / TILE_SIZE]
		[(int)(data->player.x + (new_y * TILE_SIZE / 2)) / TILE_SIZE] == '0')
	{
		data->player.x += new_y;
		data->player.y += new_x;
	}
}

void handle_movement(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = cos(data->player.dir * M_PI / 180) * MOVE_SPEED;
	new_y = sin(data->player.dir * M_PI / 180) * MOVE_SPEED;
	if (data->keys[KEY_W])
		move_forward(data, new_x, new_y);
	if (data->keys[KEY_S])
		move_backward(data, new_x, new_y);
	if (data->keys[KEY_A])
		move_left(data, new_x, new_y);
	if (data->keys[KEY_D])
		move_right(data, new_x, new_y);
}