/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:15:35 by lotrapan          #+#    #+#             */
/*   Updated: 2024/09/25 16:06:32 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

/* void	update_player(t_data *data)
{
	handle_movement(data);
	handle_rotation(data);
} */

int	game_loop(t_data *data)
{
	mlx_clear_window(data->mlx, data->window);
	render_ceiling(data);
	render_floor(data);
	render_minimap(data);
	// update_player(data);
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
	return (1);
}