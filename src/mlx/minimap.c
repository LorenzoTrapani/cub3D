/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:46:05 by lotrapan          #+#    #+#             */
/*   Updated: 2024/09/24 17:25:58 by lotrapan         ###   ########.fr       */
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
	draw_tile(&data->minimap, data->player.x - TILE_SIZE / 2, data->player.y - TILE_SIZE / 2, RED);
	// draw_rays(data);
}


void open_minimap(t_data *data)
{
	draw_minimap(data);
    mlx_put_image_to_window(data->mlx, data->window, data->minimap.minimap, 0, 0);
}


