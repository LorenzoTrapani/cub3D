/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:44:42 by lotrapan          #+#    #+#             */
/*   Updated: 2024/09/24 17:16:44 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
/* 
void draw_line(t_minimap *img, double x1, double y1, double x2, double y2, int color)
{
    int dx = fabs(x2 - x1);
    int dy = fabs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
	int err2;

    while (1) 
	{
        draw_pixel(img, (int)x1, (int)y1, color);
        if (x1 == x2 && y1 == y2)
			break;
        err2 = err * 2;
        if (err2 > -dy) 
		{
            err -= dy;
            x1 += sx;
        }
        if (err2 < dx)
		{
            err += dx;
            y1 += sy;
        }
    }
} */

/* void draw_rays(t_data *data)
{
	double start_angle = data->player.angle - (FOV / 2);
	double angle_step = FOV / NUM_RAYS;
	double player_x = (data->player.x * TILE_SIZE) + (TILE_SIZE / 2);
	double player_y = (data->player.y * TILE_SIZE) + (TILE_SIZE / 2);
	double end_x;
	double end_y;
	int i = -1;
	while (++i < NUM_RAYS)
	{
		double angle = start_angle + (i * angle_step);
		end_x = player_x + cos(angle) * 100;
		end_y = player_y + sin(angle) * 100;
		printf("Ray %d: angle=%f, end=(%f, %f)\n", i, angle, end_x, end_y);
		// draw_line(&data->minimap, data->player.x, data->player.y, end_x, end_y, RED);
	}
} */