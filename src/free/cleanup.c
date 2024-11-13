/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:04:52 by lotrapan          #+#    #+#             */
/*   Updated: 2024/11/13 16:32:41 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_texture(void *mlx, t_tex *tex)
{
	if (tex->north_img.image)
		mlx_destroy_image(mlx, tex->north_img.image);
	if (tex->south_img.image)
		mlx_destroy_image(mlx, tex->south_img.image);
	if (tex->west_img.image)
		mlx_destroy_image(mlx, tex->west_img.image);
	if (tex->east_img.image)
		mlx_destroy_image(mlx, tex->east_img.image);
}

void	cleanup(t_data *data)
{
	if (data->map.map_mtx)
		ft_free_matrix(data->map.map_mtx);
	free_texture(data->mlx, &data->tex);
}
