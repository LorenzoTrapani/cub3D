/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:59:15 by lotrapan          #+#    #+#             */
/*   Updated: 2024/09/25 17:04:59 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	render_ceiling(t_data *data)
{
	int x;
	int y;

	y = -1;
	while (++y <  WIN_HEIGHT / 2)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			draw_pixel(data->img, x, y, data->tex.ceiling);
	}
}

void	render_floor(t_data *data)
{
	int x;
	int y;

	y = WIN_HEIGHT / 2 - 1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			draw_pixel(data->img, x, y, data->tex.floor);
	}
}

void render_minimap(t_data *data)
{
	int x;
	int y;
	int color;

	y = -1;
	if (data->minimap.show == false)
		return ;
	while (++y < data->map.height)
	{
		x = -1;
		while (++x < (int)ft_strlen(data->map.map_mtx[y]))
		{
			color = data->tex.ceiling;
			if (data->map.map_mtx[y][x] == '1')
				color = GREY;
			else if (data->map.map_mtx[y][x] == '0')
				color = WHITE;
			draw_tile(data->img, x * TILE_SIZE, y * TILE_SIZE, color);
		}
	}
	draw_tile(data->img, data->player.x, data->player.y, RED);
	mlx_put_image_to_window(data->mlx, data->window, data->img, 10, 10);
}
