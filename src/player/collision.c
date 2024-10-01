/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:30:39 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/01 14:43:30 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_orizontal_collision(t_data *data, double new_x)
{
	int	map_x;
	int	new_map_x;
	int	i;

	map_x = data->player.x / TILE_SIZE;
	new_map_x = new_x / TILE_SIZE;
	i = map_x;
	while (i != new_map_x + 1 * (new_x > data->player.x)
		- 1 * (new_x < data->player.x))
	{
		if (data->map.map_mtx[(int)data->player.y / TILE_SIZE][i] == '1')
			return (1);
		if (new_x > data->player.x)
			i++;
		else
			i--;
	}
	return (0);
}

int	check_vertical_collision(t_data *data, double new_y)
{
	int	map_y;
	int	new_map_y;
	int	i;

	map_y = data->player.y / TILE_SIZE;
	new_map_y = new_y / TILE_SIZE;
	i = map_y;
	while (i != new_map_y + 1 * (new_y > data->player.y)
		- 1 * (new_y < data->player.y))
	{
		if (data->map.map_mtx[i][(int)data->player.x / TILE_SIZE] == '1')
			return (1);
		if (new_y > data->player.y)
			i++;
		else
			i--;
	}
	return (0);
}

void	orizontal_adjust(t_data *data, double dir_x)
{
	double	new_x;

	new_x = data->player.x + dir_x * 0.01;
	if (!check_orizontal_collision(data, new_x))
	{
		data->player.x = new_x;
		orizontal_adjust(data, dir_x);
	}
}

void	vertical_adjust(t_data *data, double dir_y)
{
	double	new_y;

	new_y = data->player.y + dir_y * 0.01;
	if (!check_vertical_collision(data, new_y))
	{
		data->player.y = new_y;
		vertical_adjust(data, dir_y);
	}
}