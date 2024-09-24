/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:08:08 by lotrapan          #+#    #+#             */
/*   Updated: 2024/09/24 17:09:05 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	handle_rotation(t_data *data)
{
	if (data->player.rot == 1)
	{
		if (data->player.dir + (1 + ROTATE_SPEED) > 360)
			data->player.dir = data->player.dir - 360;
		data->player.dir += (1 + ROTATE_SPEED);
	}
	if (data->player.rot == -1)
	{
		if (data->player.dir - (1 + ROTATE_SPEED) < 0)
			data->player.dir = 360 + data->player.dir;
		data->player.dir -= (1 + ROTATE_SPEED);
	}
}