/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:46:05 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/01 14:38:35 by lotrapan         ###   ########.fr       */
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
	int	radius;
	int	radius_sq;
	int	x;
	int	y;

	radius = TILE_SIZE / 2;
	radius_sq = radius * radius;
	x = -radius;
	y = -radius;
	while (x <= radius)
	{
		y = -radius;
		while (y <= radius)
		{
			if (x * x + y * y <= radius_sq)
				draw_pixel(data->img, data->player.x + x,
					data->player.y + y, RED);
			y++;
		}
		x++;
	}
}
