/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:15:35 by lotrapan          #+#    #+#             */
/*   Updated: 2024/11/11 19:19:27 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void update_player(t_data *data)
{
	handle_movement(data);
	handle_rotation(data);
}

void render_walls(t_data *data)
{
	int i;
	double planeX = 0;
	double planeY = 0.66;
	i = -1;
	while (++i < WIN_WIDTH)
	{
		double cameraX = (double)(2.0 * i) / (double)WIN_WIDTH - 1;
		double rayDirX = data->player.dir_x + planeX * cameraX;
		double rayDirY = data->player.dir_y + planeY * cameraX;
		double normalized_player_x = data->player.x / TILE_SIZE;
		double normalized_player_y = data->player.y / TILE_SIZE;
		int mapX = (int)(normalized_player_x);
		int mapY = (int)(normalized_player_y);
		double sideDistX;
		double sideDistY;
		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1.0 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1.0 / rayDirY);
		double perpWallDist;

		int stepX;
		int stepY;
		int hit = 0; // was there a wall hit?
		int side;	 // was a NS or a EW wall hit?
		if (i == WIN_WIDTH / 2)
		{
			printf("player pos x %f, y %f\n", normalized_player_x, normalized_player_y);
		}
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (normalized_player_x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - normalized_player_x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (normalized_player_y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - normalized_player_y) * deltaDistY;
		}
		// printf( "[sideDistX] %f, [sideDistY] %f\n", sideDistX, sideDistY);
		while (hit == 0)
		{
			// jump to next map square, either in x-direction, or in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			// Check if ray has hit a wall
			if (data->map.map_mtx[mapX][mapY] > 0)
				hit = 1;
		}
		/* if (i == WIN_WIDTH / 2)
		{
			printf("data->player.dir_x %f, data->player.dir_y %f\n", data->player.dir_x, data->player.dir_y);
			printf("sideDistX: %f, sideDistY: %f\n", sideDistX, sideDistY);
		} */
		if (side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);
		if (i == WIN_WIDTH / 2)
		{
			printf("perpWallDist: %f\n", perpWallDist);
		}
		int lineHeight = (int)(WIN_HEIGHT / perpWallDist);

		// calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
		if (drawEnd >= WIN_HEIGHT)
			drawEnd = WIN_HEIGHT - 1;
		int y = -1;

		while (++y < WIN_HEIGHT)
		{
			/* if (i == WIN_WIDTH / 2)
			{
				printf("[x] %d,[y] %d, [pWallDist] %d, \
			[drawStart] %d, [drawEnd] %d, [sideDistX] %f, [sideDistY] %f \n",
					   i, y, (int)perpWallDist, drawStart, drawEnd, sideDistX, sideDistY);
			} */
			/* if (i == WIN_WIDTH / 2)
			{
				printf("[drawStart] %d, [drawEnd] %d\n", drawStart, drawEnd);
			} */
			if (y < drawStart && y > drawEnd)
			{
				draw_pixel(data->img, i, y, 0xFFFFFF);
			}
		}
	}
}

int game_loop(t_data *data)
{
	mlx_clear_window(data->mlx, data->window);
	update_player(data);
	render_ceiling(data);
	render_floor(data);
	render_walls(data);
	render_minimap(data);
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
	return (1);
}
