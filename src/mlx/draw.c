/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:46:05 by lotrapan          #+#    #+#             */
/*   Updated: 2024/11/15 18:49:21 by lotrapan         ###   ########.fr       */
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
	x = -radius;
	while (x <= radius)
	{
		y = -radius;
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

void	draw_wall(t_data *data, int x, int y, int wall_bottom)
{
	int	color;

	color = 0;
	while (y <= wall_bottom)
	{
		if (y >= 0 && y < WIN_HEIGHT)
		{
			color = get_texture_color(data, data->tex.tex_x, data->tex.tex_pos);
			draw_pixel(data->img, x, y, color);
		}
		data->tex.tex_pos += data->tex.step;
		y++;
	}
}

void	draw_line_dir(t_data *data)
{
	double	new_x;
	double	new_y;
	int		i;

	i = 0;
	new_x = data->player.x * TILE_SIZE;
	new_y = data->player.y * TILE_SIZE;
	while (i < 20)
	{
		new_x += data->player.dir_x;
		new_y += data->player.dir_y;
		draw_pixel(data->img, new_x, new_y, RED);
		i++;
	}
}
