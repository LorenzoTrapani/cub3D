/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:46:05 by lotrapan          #+#    #+#             */
/*   Updated: 2024/11/12 14:53:36 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = img->data + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_tile(t_img *img, int x, int y, int color)
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

void	draw_player(t_data *data)
{
	int	player_x;
	int	player_y;
	int	radius;
	int	x;
	int	y;

	radius = TILE_SIZE / 2;
	player_x = data->player.x * TILE_SIZE;
	player_y = data->player.y * TILE_SIZE;
	x = - radius;
	while (x <= radius)
	{
		y = - radius;
		while (y <= radius)
		{
			if (x * x + y * y <= radius * radius)
				draw_pixel(data->img, player_x + x,
					player_y + y, RED);
			y++;
		}
		x++;
	}
}
