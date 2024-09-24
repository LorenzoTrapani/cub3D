/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:15:35 by lotrapan          #+#    #+#             */
/*   Updated: 2024/09/24 17:04:36 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3D.h"

void	load_player(t_data *data)
{
	handle_rotation(data);
	handle_movement(data);
}

int	load_game(t_data *data)
{
	load_player(data);
	open_minimap(data);
	return (1);
}