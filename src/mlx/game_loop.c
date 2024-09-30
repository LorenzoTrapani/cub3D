/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:15:35 by lotrapan          #+#    #+#             */
/*   Updated: 2024/09/30 17:54:33 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

void	update_player(t_data *data)
{
	handle_movement(data);
	handle_rotation(data);
}

int	game_loop(t_data *data)
{
	mlx_clear_window(data->mlx, data->window);
	update_player(data);
	printf("dir_x = %f, dir_y = %f, dir_angle = %f\n", data->player.dir_x, data->player.dir_y, data->player.dir_angle);
	render_ceiling(data);
	render_floor(data);
	render_minimap(data);
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
	return (1);
}