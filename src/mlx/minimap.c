/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:46:05 by lotrapan          #+#    #+#             */
/*   Updated: 2024/09/20 17:50:10 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void draw_pixel(t_minimap *img, int x, int y, int color)
{
	char *dst;

	if (x < 0 || x >= MAP_WIDTH|| y < 0 || y >= MAP_HEIGHT)
		return ;
	dst = img->minimap->data + (y * img->minimap->size_line + x * (img->minimap->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_tile(t_minimap *img, int x, int y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < TILE_SIZE)
	{
		j = -1;
		while (++j < TILE_SIZE)
			draw_pixel(img, x + i, y + j, color);
	}
}

void draw_player(t_data *data)
{
	double x;
	double y;

	x = data->player.x;
	y = data->player.y;
	if (data->map.map_mtx[(int)y][(int)x + 1] == '1')
		x = (int)x;
	if (data->map.map_mtx[(int)y + 1][(int)x] == '1')
		y = (int)y;
	draw_tile(&data->minimap, x * TILE_SIZE, y * TILE_SIZE, RED);
}

void draw_minimap(t_data *data)
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
			color = BLACK;
			if (data->map.map_mtx[y][x] == '1')
				color = GREY;
			else if (data->map.map_mtx[y][x] == '0')
				color = WHITE;
			draw_tile(&data->minimap, x * TILE_SIZE, y * TILE_SIZE, color);
		}
	}
	draw_player(data);
}


void open_minimap(t_data *data)
{
	draw_minimap(data);
    mlx_put_image_to_window(data->mlx, data->window, data->minimap.minimap, 10, 10);
}


