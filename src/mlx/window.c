/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:39:31 by lotrapan          #+#    #+#             */
/*   Updated: 2024/10/02 13:33:18 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	close_window(t_data *data)
{
	cleanup(data);
	if (data->mlx && data->window)
		mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_window(data);
	if (keycode == XK_w)
		data->keys[0] = 1;
	if (keycode == XK_s)
		data->keys[1] = 1;
	if (keycode == XK_a)
		data->keys[2] = 1;
	if (keycode == XK_d)
		data->keys[3] = 1;
	if (keycode == XK_Right)
		data->keys[4] = 1;
	if (keycode == XK_Left)
		data->keys[5] = 1;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == XK_w)
		data->keys[0] = 0;
	if (keycode == XK_s)
		data->keys[1] = 0;
	if (keycode == XK_a)
		data->keys[2] = 0;
	if (keycode == XK_d)
		data->keys[3] = 0;
	if (keycode == XK_Right)
		data->keys[4] = 0;
	if (keycode == XK_Left)
		data->keys[5] = 0;
	if (keycode == XK_m)
		data->minimap.show *= -1;
	return (0);
}

void	open_window(t_data *data)
{
	data->window = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx_hook(data->window, KeyPress, KeyPressMask, &key_press, data);
	mlx_hook(data->window, KeyRelease, KeyReleaseMask, &key_release, data);
	mlx_hook(data->window, DestroyNotify, StructureNotifyMask,
		&close_window, data);
}
