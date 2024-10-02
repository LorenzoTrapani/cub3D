/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:05:27 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/02 12:19:12 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/* void	orizontal_adjust(t_data *data, double dir_x)
{
	double	new_x;

	new_x = data->player.x + dir_x;
	if (!check_orizontal_collision(data, new_x))
	{
		data->player.x = new_x;
		orizontal_adjust(data, dir_x);
	}
}

void	vertical_adjust(t_data *data, double dir_y)
{
	double	new_y;

	new_y = data->player.y + dir_y;
	if (!check_vertical_collision(data, new_y))
	{
		data->player.y = new_y;
		vertical_adjust(data, dir_y);
	}
} */

void	move_forward_back(t_data *data, bool forward)
{
	const double dir = (double[2]){-1.0, 1.0}[forward];
	double	new_x;
	double	new_y;

	new_x = dir * MOVE_SPEED * data->player.dir_x + data->player.x;
	new_y = dir * MOVE_SPEED * data->player.dir_y + data->player.y;
	if (!check_orizontal_collision(data, new_x))
		data->player.x = new_x;
	if (!check_vertical_collision(data, new_y))
		data->player.y = new_y;
}

void	move_left_right(t_data *data, bool is_left)
{
	const double	dir_x = (double[2]){-1.0, 1.0}[is_left];
	const double	dir_y = (double[2]){1.0, -1.0}[is_left];
	double	new_x;
	double	new_y;

	new_x = dir_x * MOVE_SPEED * data->player.dir_y + data->player.x;
	new_y = dir_y * MOVE_SPEED * data->player.dir_x + data->player.y;
	if (!check_orizontal_collision(data, new_x))
		data->player.x = new_x;
	if (!check_vertical_collision(data, new_y))
		data->player.y = new_y;
}

void	handle_movement(t_data *data)
{
	if (data->keys[0] == 1 || data->keys[1] == 1)
		move_forward_back(data, data->keys[0] == 1);
	if (data->keys[2] == 1 || data->keys[3] == 1)
		move_left_right(data, data->keys[2] == 1);
}
