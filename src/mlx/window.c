/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:39:31 by lotrapan          #+#    #+#             */
/*   Updated: 2024/09/24 17:30:35 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	close_window(t_data *data)
{
	cleanup(data);
	if (data->mlx && data->window)
		mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_image(data->mlx, data->minimap.minimap);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_window(data);
	if (keycode == KEY_W)
		data->keys[KEY_W] = 1;
	if (keycode == KEY_S)
		data->keys[KEY_S] = 1;
	if (keycode == KEY_A)
		data->keys[KEY_A] = 1;
	if (keycode == KEY_D)
		data->keys[KEY_D] = 1;
	if (keycode == KEY_LEFT)
		data->player.rot = 1;
	if (keycode == KEY_RIGHT)
		data->player.rot = -1;
	if (keycode == KEY_M)
		data->minimap.show = true;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->keys[KEY_W] = 0;
	if (keycode == KEY_S)
		data->keys[KEY_S] = 0;
	if (keycode == KEY_A)
		data->keys[KEY_A] = 0;
	if (keycode == KEY_D)
		data->keys[KEY_D] = 0;
	if (keycode == KEY_M)
		data->minimap.show = false;
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		data->player.rot = 0;
	return (0);
}

void	open_window(t_data *data)
{
	data->window = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	init_player(data);
	mlx_hook(data->window, KeyPress, KeyPressMask, &key_press, data);
	mlx_hook(data->window, KeyRelease, KeyReleaseMask, &key_release, data);
	mlx_hook(data->window, DestroyNotify, StructureNotifyMask, &close_window, data);
	mlx_loop_hook(data->mlx, &load_game, data);
    data->minimap.minimap = mlx_new_image(data->mlx, MAP_WIDTH, MAP_HEIGHT);
}

