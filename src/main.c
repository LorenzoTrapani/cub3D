/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:06:51 by lotrapan          #+#    #+#             */
/*   Updated: 2024/11/15 17:38:02 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data = (t_data){0};
	if (!file_validation(&data, argc, argv))
		return (0);
	data.mlx = mlx_init();
	init_keys(&data);
	init_textures(&data);
	open_window(&data);
	mlx_loop_hook(data.mlx, &game_loop, &data);
	mlx_loop(data.mlx);
	return (1);
}
